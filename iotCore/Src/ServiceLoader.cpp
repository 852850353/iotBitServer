#ifndef SERVICELOADER
#define SERVICELOADER

#include <map>
#include <string>
#include "iotService_Infc.h"
class ServiceLoader
{
public:
    ServiceLoader(){}

private:
    std::map<std::string,iotService_Infc> m_ServiceMap;
};

#endif //SERVICELOADER
