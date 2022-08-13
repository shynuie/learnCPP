#include <iostream>

using namespace std;

int main(void){
    int n = 11;
    cout << n << endl;
    // 宣告一整數型指標變量 ‘np’ 為指向整數變量 n 的指標
    int *np = &n;  // & 是取址運算子
    cout << np << endl;
    int t = *np; // * 是取值運算子
    cout << t << endl;
    return 0;
}