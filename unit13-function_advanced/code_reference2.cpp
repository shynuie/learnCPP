#include <iostream>

using namespace std;

int main(void)
{
    int machineA = 1;
    int machineB = 2;
    int &device = machineA; // 將device作為machine的reference
    printf("device before reassign:%d\n", device);
    printf("machineA before reassign:%d\n", machineA);
    device = machineB;
    printf("device after reassign:%d\n", device);
    printf("machineA before reassign:%d\n", machineA);
}