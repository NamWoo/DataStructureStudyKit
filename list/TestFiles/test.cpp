#include "Tester.h"
#include <iostream>
int myStrlen(const char* str,int num)
{
    char* p = (char*)str;
    int cnt=0;
    while (*p++)
    {
        cnt++;
    }
    return cnt+num;
}


int main()
{
    Tester<VaFunc_t,const char*, int> tester((VaFunc_t)myStrlen,5);
    tester.TestRegisteredFunc(5,"asdf",1);
    tester.TestRegisteredFunc(7,"asdf",0);
    tester.TestRegisteredFunc(6,"asdf",2);
    tester.TestRegisteredFunc(6,"asdfe",1);
    tester.TestRegisteredFunc(5,"asdf",1);
    
}

