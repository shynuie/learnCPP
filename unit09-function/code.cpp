#include <iostream>

using namespace std;


int add(int, int);

int main(){
    int result = add(10, 20);
    printf("%d\n", result);
    return 0;
}

int add(int arg1, int arg2){
    return (arg1 + arg2);
}