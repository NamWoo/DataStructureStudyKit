#include "Tester.h"
#include <iostream>
int myStrlen(const char* str,int num)
{
    char* p = (char*)str;
    int cnt=0;
    while (*p++)
    {
        std::cout<<cnt++;
    }
    std::cout<<std::endl;
    return 0;
}


int main()
{
    Tester<VaFunc_t,const char*, int>::TestFunc((VaFunc_t)myStrlen,"asdf",30);
}

