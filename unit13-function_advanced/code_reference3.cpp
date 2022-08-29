#include <iostream>

using namespace std;

int main(void)
{
    int machineA = 1;
    int machineB = 2;
    int *machinePr = &machineA;
    int &device = *machinePr; // 將device作為machineAPr的值的reference
    printf("value of pointer before reassign:%d\n", *machinePr);
    printf("device before reassign pointer:%d\n", device);
    printf("machineA before reassign pointer:%d\n\n", machineA);
    machinePr = &machineB;
    printf("value of pointer before reassign:%d\n", *machinePr);
    printf("device after reassign pointer:%d\n", device);
    printf("machineA before reassign pointer:%d\n", machineA);
}