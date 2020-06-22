#include "irqSubSystem.h"

struct IRQ_INFOR
{
    int8_t priority;
    std::string irqName;
    irqSubSystem::Functor* functor;
    std::string bindName;

    bool operator == (IRQ_INFOR& info);

    std::string information();
};

static std::list<IRQ_INFOR> _irqList;			//注册列表
static std::vector<int8_t> _irqBlockPriority;           //中断等级屏蔽列表
static std::vector<std::string> _irqBlockIRQName;	//中断名称屏蔽列表
static std::vector<irqSubSystem::Functor*> _irqBlockFunctor;		//中断处理函数屏蔽列表

void irqSubSystem::IRQ_REG(int8_t priority, std::string irqName,Functor* func, std::string BindName)
{
    IRQ_INFOR irqInfo{priority,irqName,func,BindName};
    std::list<IRQ_INFOR>::iterator itera = _irqList.begin();
    while(itera != _irqList.end())
    {
        if(irqInfo == *itera)
        {
            std::cerr << "Currently registered IRQ name conflict: " << irqName << std::endl;
            return;
        }
        itera ++;
    }
    _irqList.push_back(irqInfo);
    return;
}

void irqSubSystem::IRQ_Call(std::string irqName)
{
    std::list<IRQ_INFOR>::iterator itera = _irqList.begin();
    while(itera != _irqList.end())
    {
        if(irqName == itera->irqName)
        {
            if(std::end(_irqBlockPriority) == std::find(std::begin(_irqBlockPriority),std::end(_irqBlockPriority),itera->priority))// 未找到屏蔽中断
            {
                itera->functor();
            }
        }
        itera ++;
    }
    return;
}

void irqSubSystem::IRQ_BlockPriority(int8_t priority)
{
    if(_irqBlockPriority.end() != std::find(_irqBlockPriority.begin(),_irqBlockPriority.end(),priority))
    {
        std::cerr << "IRQ_BlockPriority, The current interrupt has been blocked" << std::endl;
        return;
    }
    _irqBlockPriority.push_back(priority);
    return;
}

void irqSubSystem::IRQ_BlockIRQName(std::string irqName)
{
    if(_irqBlockIRQName.end() != std::find(_irqBlockIRQName.begin(),_irqBlockIRQName.end(),irqName))
    {
        std::cerr << "IRQ_BlockIRQName, The current interrupt has been blocked" << std::endl;
        return;
    }
    _irqBlockIRQName.push_back(irqName);
    return;
}

void irqSubSystem::IRQ_BlockFunctor(irqSubSystem::Functor *func)
{
    if(_irqBlockFunctor.end() != std::find(_irqBlockFunctor.begin(),_irqBlockFunctor.end(),func))
    {
        std::cerr << "IRQ_BlockFunctor, The current interrupt has been blocked" << std::endl;
        return;
    }
    _irqBlockFunctor.push_back(func);
    return;
}

void irqSubSystem::IRQ_QueryPriority(int8_t priority)
{
    std::cout << "============================== IRQ_QueryPriority ==============================\n" ;
    std::list<IRQ_INFOR>::iterator itera = _irqList.begin();
    while(itera != _irqList.end())
    {
        if(priority == itera->priority)
        {
            std::cout << itera->information() << std::endl;
        }
        itera ++;
    }
    std::cout << "===============================================================================\n" ;
}

void irqSubSystem::IRQ_QueryIRQName(std::string irqName)
{
    std::cout << "============================== IRQ_QueryIRQName ==============================\n" ;
    std::list<IRQ_INFOR>::iterator itera = _irqList.begin();
    while(itera != _irqList.end())
    {
        if(irqName == itera->irqName)
        {
            std::cout << itera->information() << std::endl;
        }
        itera ++;
    }
    std::cout << "===============================================================================\n" ;
}



void irqSubSystem::IRQ_QueryFunctor(irqSubSystem::Functor *func)
{
    std::cout << "============================== IRQ_QueryFunctor ==============================\n" ;
    std::list<IRQ_INFOR>::iterator itera = _irqList.begin();
    while(itera != _irqList.end())
    {
        if(func == itera->functor)
        {
            std::cout << itera->information() << std::endl;
        }
        itera ++;
    }
    std::cout << "===============================================================================\n" ;
}


void irqSubSystem::IRQ_QueryBindName(std::string bindName)
{
    std::cout << "============================== IRQ_QueryBindName ==============================\n" ;
    std::list<IRQ_INFOR>::iterator itera = _irqList.begin();
    while(itera != _irqList.end())
    {
        if(bindName == itera->bindName)
        {
            std::cout << itera->information() << std::endl;
        }
        itera ++;
    }
    std::cout << "===============================================================================\n" ;
}

bool IRQ_INFOR::operator ==(IRQ_INFOR &info)
{
    if(priority == info.priority
            && irqName == info.irqName
            && functor == info.functor
            && bindName == info.bindName)
        return true;
    return false;
}

std::string IRQ_INFOR::information()
{
    char buf[256]={0};
    sprintf(buf,"IRQ_INFOR { priority:%d, irqName:\"%s\",  functor:0x%X, bindName:\"%s\"}",(int)priority,irqName.c_str(),functor,bindName.c_str());
    return buf;
}
