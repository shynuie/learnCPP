#include <iostream>

using namespace std;

void add_value(int x){
    x += 10;
    printf("x in function (pass by value):%d\n", x);
}

void add_reference(int &x){
    x += 10;
    printf("x in function (pass by reference):%d\n", x);
}


int main(void){
    int x = 10;
    printf("x before function (pass by value):%d\n",x);
    add_value(x);
    printf("x after function (pass by value):%d\n", x);
    add_reference(x);
    printf("x after function (pass by reference):%d\n",x);
}