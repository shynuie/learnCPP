# Hello C++

## Hello world
----
C++ 是一種需要編譯器編譯，產生執行檔的語言，腳本代碼檔案通常會以.cpp （C plus plus）作為副檔名，流程如下：

1. 編寫腳本代碼檔案 -> 檔案.cpp
2. 檔案.cpp -> 編譯器 -> 可執行檔
3. 若要執行腳本，則執行可執行檔。
----
    hint: 
    在windows裡，編譯出來的可執行檔副檔名通常為.exe，而在linux或MacOS中，編譯出來的檔案其副檔名通常為.out。
----

### *編譯器*
常見內建的C++編譯器為g++，編譯檔案也很容易，打開terminal後，執行以下編譯命令：

    g++ <檔案路徑.cpp> -o <執行檔路徑>

<檔案路徑.cpp>  
    C++代碼檔案的路徑，通常我會先將terminal cd到檔案所在directory後，再執行編譯命令，此時直接給檔名即可。  

<執行檔路徑>  
    編譯完成，輸出的執行檔需要儲存的指定路徑（檔名）。
    若不指定路徑，則會在當前working directory下生成 a.out 或 a.exe 檔，視操作系統而定。
  
----
### *開始敲hello代碼吧！*  

terminal 裡touch 一個'hello.cpp'檔後，將以下代碼敲入或者複製進這個hello.cpp檔案裡。

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

這邊先不對代碼作太多解釋，後面章節會一一解釋到。
這裡比較需要先知道的知識點可能就幾個地方：  

在C++裡 
1. ‘//’ 表示單行註解；
2. 以‘/\*’ 與 '\*/' 夾住跨行註解；
3. 'cout' 表示輸出物件， '<<' 為左移位運算子，'endl' 表示換行符號。

接著，如同代碼裡註解的說明一樣，我們將這個代碼檔案存檔，同時打開terminal，cd到當前文件所在後，敲入：  

    g++ <檔案名.cpp> -o hello

這時這個資料夾應該會跑出一個檔案，叫做hello，我們接著在terminal裡給以下命令要求執行這個執行檔：

    ./hello

運行完，你應該會在你的terminal裡看到以下輸出：

    Hello world!
