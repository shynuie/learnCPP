#include <iostream>

using namespace std;

inline int add(int arg1, int arg2) { return arg1 + arg2; }

int main(void)
{
    printf("%d\n", add(10, 20));
}