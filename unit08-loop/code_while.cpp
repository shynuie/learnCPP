#include <iostream>

using namespace std;

int main(void){
    int i = 10;
    while (i > 0){
        printf("i = %d\n", i);
        i--;
    }
    int j = 10;
    while (true){
        if (j == 5){
            break;
        }
        printf("j = %d\n", j);
        j--;
    }
}