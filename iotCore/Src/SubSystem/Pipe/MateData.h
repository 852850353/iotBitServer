#ifndef MATEDATA
#define MATEDATA

#include <string>
#include <tuple>
#include <bits/stdc++.h>

std::bitset<10> a;
template <typename T>
class iotMateData
{
public:
    iotMateData(std::string name)
    {
        m_name = std::string(name);
    }

    void operator = (T var)
    {
        *((T*)(&m_data)) = var;
    }

    std::string& name()
    {
        return m_name;
    }

    T& var()
    {
        return *(T*)(m_data);
    }

    uint8_t* address()
    {
        return &m_data;
    }

private:
    std::string m_name;
    uint8_t m_data[sizeof(T)];
    size_t offset = sizeof(T);

private:
    T& cvt(void* data)
    {
        return static_cast<T&>(data);
    }
};

#define iotGetName(x) #x
#define iotRegClass(clazz)  \
    new iotMateData<clazz>(iotGetName(clazz))
#define iotRegFunctor(func) iot

#define iotSignal(func) #func
#define iotSlot(func) #func
#define iotSender(clazz) #clazz
#define iothardler(clazz) #clazz

#define iotConnect(sender,signal,hander,slot) new ConnectPrivate<decltype(x),decltype(fs),decltype(y),decltype(fl)>();

namespace iot
{
enum connectType
{
    AutoConnection = 0,
    DirectConnection,
    QueuedConnection,
    BlockingQueuedConnection,
    UniqueConnection,
    AutoCompatConnection,
};
}

#endif //MATEDATA
