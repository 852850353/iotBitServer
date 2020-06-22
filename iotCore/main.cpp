#include <functional>
#include <iostream>
#include <map>

void g_Add(int a)
{
 std::cout<<a;
}


int main()
{
    std::function<decltype(g_Add)> f = g_Add;
    f(2);
    return 0;
}
