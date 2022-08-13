// 引入標準io程式庫
#include <iostream>
// 引入字串程式
#include <string>

// std 為標準程式庫的命名空間
using namespace std;


int main(void){
    string m("Hello world!");  //透過建構函數 string 建立字串變量 ‘m’
    cout << endl << m << endl << endl << endl;  // 'cout' 輸出物件, '<<' 運算子, 'endl' 換行符號
    return 0;
}

/*
至此代碼完成，存檔後在terminal cd至當下資料夾，輸入：

    g++ hello.cpp -o hello.out
    
以 g++ 編譯 cpp檔，得到 hello.out執行檔
*/