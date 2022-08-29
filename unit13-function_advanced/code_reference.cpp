#include <iostream>

using namespace std;

int main(void)
{
    int machine = 1;
    int &device = machine; // 將device作為machine的reference
    printf("machine before device++:%d\n", machine);
    device++;
    printf("machine after device++:%d\n", machine);
}