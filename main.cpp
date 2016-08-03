#include <iostream>

int test1()
{
    // exit normally
    return 0;
}

int test2();

int main()
{
    int a   = 0;
    int res = -1;

    // some code here
    res = test1();


    // some other code

    // alabala
    // ne mi se otvarq visual studio
    // zatova go karam prez notepada

    res &= test2();

    // program exit normally
    return 0;
}

int test2()
{
    return 1;
}
