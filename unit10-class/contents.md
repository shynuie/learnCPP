# Unit10 - 類別 class

## I. 什麼是類別
----

類別(class)是用來設計自己需要的物件(object)：
1. 類別 = 設計圖
2. 物件 = 依據設計圖生產出的物品

類別底下包含了多個成員，依照成員的種類，可以區分為：
1. 資料成員 (data member):  
    專屬於類別的變量
2. 成員函數 (member function)
    專屬於類別的函數
3. 建構函數 (constructor)
    構建該類別物件的函數  

例如，設計一種類別叫做‘學生’，學生自身帶有資料（資料成員）：姓名、學號、班別...，接著學生有幾種功能（成員函數）：上課、唸書、吃飯、午休...等等。那屬於這個類別的物品...呃或者說生物？就都會有姓名、學號，同時都會上課、唸書、吃飯。

    hint: 建構函數沒有回傳值，可以想像成建構函數預設回傳物件自己本身，因此無需宣告回傳值。

## II. 權限

在設計類別的過程裡，我們必須透過存取標籤(access label) `public` 或 `private`將成員的權限歸類：
* `public`：成員可以在程式中的任何地方存取；
* `private`：成員只可以在同個類別裡被存取；

例如，我們設計一種類別來表示教職員，教職員裡有成員函數：`上課`、`開早會`；而此時我們又另外設計一個類別叫做主任，主任算是教職員的一種，所以我們選擇直接繼承教職員（繼承的觀念後續會講到，可以先想成我們直接用教職員的模板，生成一個新的類別叫做主任）。但我們都知道，主任不用上課，只需要開早會就好。所以在這個例子中，`上課`這個函數，是僅限定給純教職員的人員的，那我們就可以考慮將`上課`這個函數設定為`private`，而`開早會`這個函數則可以設定為`public`。

範例代碼  

    #include <iostream>

    using namespace std;

    // 宣告類別
    class Students
    {
    public:
        int student_id;
        int class_id;
        string name;
        void DoStudy();
        void DoLearn();
        void DoHaveLunch();
        void DoNap();
    };

    // 實作 Students 中的 DoStudy() 成員函數
    void Students::DoStudy()
    {
        printf("I'm studying...\n");
    }

    int main(void)
    {
        Students marvin;
        marvin.student_id = 1;
        marvin.class_id = 101;
        marvin.name = "Marvin";
        marvin.DoStudy();
        return 0;
    }
代碼中，我們在實作Students的`DoStudy()`成員函數時，透過`Students`加上兩個冒號`::`表明了`DoStudy()`是屬於`Students`類別的函數。連續兩個冒號`::`是作用域運算子(scope operator)。沒有這樣寫的話，編譯器會把`DoStudy()`當作一般函數實作。

    Hint：目前每次編寫cpp檔案時，我們都會先標明 using namespace std;，其實就是在告訴編譯器，若沒特別聲明，代碼中調用的函數都是來自於std這個類別的成員函數。