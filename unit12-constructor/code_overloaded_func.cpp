#include <iostream>


int add(int arg1, int arg2);
double add(double arg1, int arg2);

int add(int arg1, int arg2){
    return (arg1 + arg2);
}

double add(double arg1, int arg2){
    return (arg1 + (double)arg2);
}

int main(void){
    printf("%d\n", add(2,3));
    printf("%f\n", add(2.0,3));
}