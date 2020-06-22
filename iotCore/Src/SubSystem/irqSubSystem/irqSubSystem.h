#ifndef IRQSUBSYSTEM
#define IRQSUBSYSTEM

#include <string>
#include <functional>
#include <list>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

//一个中断可执行多个中断函数逻辑

namespace irqSubSystem
{

//中断函数类型声明
typedef void(Functor)(void);

//irq message hander function template
void IRQ_HanderFunctor(){return;}

//中断注册
void IRQ_REG(int8_t priority,std::string irqName,Functor* func,std::string BindName);

//中断逻辑处理调用
void IRQ_Call(std::string irqName);

//屏蔽中断等级
void IRQ_BlockPriority(int8_t priority);

//屏蔽中断名称
void IRQ_BlockIRQName(std::string irqName);

//屏蔽中断函数
void IRQ_BlockFunctor(Functor* func);

//中断等级信息查询
void IRQ_QueryPriority(int8_t priority);

//中断名称信息查询
void IRQ_QueryIRQName(std::string irqName);

//中断处理函数信息查询
void IRQ_QueryFunctor(Functor* func);

//中断处理函数名称信息查询
void IRQ_QueryBindName(std::string bindName);

//变量字符串化
#define _toString(x) #x

//中断注册
#define IRQ_REGISTER(priority,irqName,func)(irqSubSystem::IRQ_REG(priority,irqName,func,_toString(func)))

//中断触发
#define IRQ_TRIGGER(irqName)(irqSubSystem::IRQ_Call(irqName))

//屏蔽中断等级
#define IRQ_BLOCK_PRIORITY(irqPriority)(irqSubSystem::IRQ_BlockPriority(irqPriority))

//中断等级信息查询
#define IRQ_QUERY_PRIORITY(irqPriority)(irqSubSystem::IRQ_QueryPriority(irqPriority))

//中断名称信息查询
#define IRQ_QUERY_IRQNAME(irqName)(irqSubSystem::IRQ_QueryIRQName(irqName))

//中断处理函数信息查询
#define IRQ_QUERY_FUNCTOR(functor)(irqSubSystem::IRQ_QueryFunctor(functor))
}

#endif //IRQSUBSYSTEM
