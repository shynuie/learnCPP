#include <iostream>

using namespace std;

int main(void){
    int selection = 4;
    switch(selection){
        case 0:
            printf("select 0\n");
            break;
        case 1:
            printf("select 1\n");
            break;
        case 2:
            printf("select 2\n");
            break;
        case 3:
            printf("select 3\n");
            break;
        default:
            printf("No selection.\n");
            break;
    }
}