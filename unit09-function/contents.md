# Unit9 - 函數 function

定義函數需要先給定三個信息：
1. 回傳值的型態
2. 函數名稱
3. 參數列

定義一個加法函數：

    int add(int a, int b)  // 回傳值型態 函數名稱(參數列)

接著設計函數的操作邏輯

    int add(int a, int b){
        return (a + b);
    }

函數若沒有返回值，或者不需要參數，可以寫void，參數列可以寫void或者留白，例如：

    void SayHello(){
        printf("Hello!\n");
    }