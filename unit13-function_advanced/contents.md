# Unit13 - 函數进阶

## I. 内嵌函數  

代碼檔案經編譯變為一組機器語言指令，程序在執行時，作業系統將這些指令載入電腦的記憶體中，所以每行指令都有其特定的記憶體位址。接著電腦逐行執行這些指令，當碰到迴圈或選擇敘述時，電腦會跳過某些指令，直接前往特定的位址執行指令。而一般的函數呼叫也會使電腦跳到另一個位址（函數的位址），然後當函數結束後再跳回。

### *程式内部运作一般函数的方式*
----
以下為一個由兩條指令加一條函數所組成的程序，假設記憶體位址分別為：1，2，3

    1. 指令A 
    2. 函數B  
    3. 指令C

範例中，電腦執行完指令A後，遇到函數B呼叫指令，此時電腦會將指令C的記憶體位址儲存下來，接著`拷貝`函數B的引數至記憶體堆疊上。然後緊接著跳到函數B具體的記憶體位址，執行函數B的指令集（也許會放置回傳值到記憶體上），最後根據儲存的位址紀錄，回到指令C的位址。

所以其真實的運行流程與記憶體概覽如下 （小括弧內代表實際執行順序）：

    0. 3
    1. 指令A （1st） // 程序起始點
    2. 在記憶體位址0儲存下一個指令的位址：3，同時拷貝引數到記憶體位址99，跳到函數B位址：11 (2nd)
    3. 指令C (6th)
    .
    .
    .
    11. 函數B的指令A (3rd)
    12. 函數B的指令B (4th)
    13. 返回位址0指定的記憶體位址 (5th)
    99. 函數引數

然而，若是函數在其他位址被大量的重複使用，則意味著，程序會不斷往返函數指令實際所在的位址；在範例中，就會不斷跳回到位址11～13。這意味著物理上有不少時間會花在移動指針（讀取記憶體的裝置）上，尤其當引用函數的指令若位在離函數較遠的記憶體位址時。可以想像成，假設你住在巷頭，親戚家在巷尾，巷尾有一間便利店，而你每天不論到親戚家或者回到家都會被吩咐去便利店買一桶水。當你從便利店提著水時，你覺得到親戚家的距離還好，一下就到了，但提著水回家時，巷尾到巷頭的距離就顯得相當遙遠，尤其如果一天要買多桶水，那這個來回的成本就顯得相當龐大。

### *程式内部运作內嵌函数的方式*
----

內嵌函數提供了一種方式來減少呼叫函數時的時間成本，概念很簡單，如果去巷尾便利店來回買水很辛苦，那在家裡樓下多開一間便利店不就好了，這樣我只需要樓上樓下來回即可。以剛剛的範例來說，就會變成：

    1. 指令A （1st） // 程序起始點
    2. 拷貝引數到記憶體位址99 (2nd)
    3. 函數B的指令A （3rd）
    4. 函數B的指令B （4th）
    5. 指令C (5th)
    .
    .
    .
    99. 函數引數

也就是將函數改寫到原先呼叫函數的指令位址，這樣就省下了一些移動距離。那假設指令C之後又有調用到函數B的情況又該怎麼辦呢？再多開一間便利店就OK啦（誤）

    1. 指令A （1st） // 程序起始點
    2. 拷貝引數到記憶體位址99 (2nd)
    3. 函數B的指令A （3rd）
    4. 函數B的指令B （4th）
    5. 指令C (5th)
    6. 拷貝引數到記憶體位址99 (6th)
    7. 函數B的指令A （7th）
    8. 函數B的指令B （8th）
    .
    .
    .
    99. 函數引數

### *使用內嵌函數*
----
要將一個函數宣告為內嵌函數很簡單，只需在宣告一般函數前加個前置關鍵字`inline`即可，範例代碼：

    #include <iostream>

    using namespace std;

    inline int add(int arg1, int arg2) { return arg1 + arg2; }

    int main(void)
    {
        printf("%d\n", add(10, 20));
    }


### *以RAM空間換取運行時間*
----
使用內嵌函數的好處是，這大幅減低了讀取函數的移動距離，增加了程式的運行效率。但也不難想像，一個內嵌函數被多次調用的話，程式就會付出大量的RAM空間，插入多份函數的程式碼，因此選擇使用一般函數還是內嵌函數時，可以先分別從時間與運作邏輯來分析函數本身，再做決定。

### *使用一般函數還是內嵌函數？*
----
a. 若處理函數的時間大於呼叫函數所需的時間，則透過內嵌函數能減少的僅是總體時間的一小部分，那以RAM換來的時間就顯得有點不划算；  

b. 若處理函數的時間小於呼叫函數所需的時間，則透過內嵌函數減少的時間就佔了總體所需時間的一大部分，那損失的RAM空間就相對顯得划算；

c. 若函數被重複調用的次數夠多，那使用內嵌函數省下的時間也會相當可觀，此時使用內嵌函數就相當有效，但要小心的是，如果呼叫的次數過高，RAM的使用量也會相對很高；

    Hint:
    編譯器在以下2種情況是有可能不鳥你的內嵌函數要求的：
    1. 函數過於龐大。如果函數定義不能放在一到兩行內，那這個函數可能不適合做內嵌函數；
    2. 函數呼叫了自己（遞迴）；


## II. reference 變數
----

`reference變數`(reference variable)是C++語言新增的一種複合型態，可以想像成是已定義變數的別名，或是另一個名稱。例如：假設有一變數machine代表機器，當宣告device為變數machine的reference時，則device跟machine都可以交替代表機器。

為何需要這種別名？reference的主要用途在於作為函數的形式引數，將reference當作引數，函數處理的是原始資料，而非副本。

### *產生一個reference變數*
----
C和C++以`&`符號代表取址運算子，但C++賦予了`&`符號額外的意義：宣告`reference`。以剛剛的機器例子：

    #include <iostream>

    using namespace std;

    int main(void)
    {
        int machine = 1;
        int &device = machine; // 將device作為machine的reference
        printf("machine before device++:%d", machine);
        device++;
        printf("machine after device++:%d", machine);
    }

這段代碼裡，&並非取址運算子，而是型態識別字的一部分。就如宣告中 `int *` 表示指向`int`的指標。 這裡的`int &`表示reference到`int`。reference的宣告使我們可以交互使用machine跟device，二者都參考到相同的值以及相同的記憶體位址。所以對device + 1，machine的值也會改變。

    hint:
    reference必須在宣告時就完成初始化（賦值），不能像指標一樣，先宣告後賦值。

### *reference是不可改變指向的對象的*
----
reference 比較像 `const` 指標；當我們宣告`reference`時必須將其賦值，且當reference指向特定變數時，就不能再改變指向的目標了。  

舉例來說，下面reference `device`：

    int & device = machine;

與指標:

    int * const machine_pointer = &machine

兩種變量中，`*machine_pinter`與`device`是具有相同功能的。  

下面代碼（reference_2）演示若我們打算將一個reference重新指派給另外一個變量，會發生什麼事：

    #include <iostream>

    using namespace std;

    int main(void)
    {
        int machineA = 1;
        int machineB = 2;
        int &device = machineA; // 將device作為machine的reference
        printf("device before reassign:%d\n", device);
        printf("machineA before reassign:%d\n", machineA);
        device = machineB;
        printf("device after reassign:%d\n", device);
        printf("machineA before reassign:%d\n", machineA);
    }
代碼裡，我們想將reference device從一開始指向A，改指向到B。然而實際運作後，會發現，經過語句：

    device = machineB;

後，雖然device的確變成machineB的值2，但machineA的值也跟著變成了2。意味著上面這個語句，並不是代表將device指向到machineB，而是將machineB的值，設值到了machineA的原始值上了。原因就在于，device這個reference變數，在指定refer的對象machineA後，所有對它的操作都會反應到原始資料，即machineA的值上，所以`device = machineB`這句話，等價於`machineA = machineB`，亦即將machineB的值，設值到machineA身上。

reference這種不可更改指向的特性，與pointer不同：

    #include <iostream>

    using namespace std;

    int main(void)
    {
        int machineA = 1;
        int machineB = 2;
        int *machinePr = &machineA;
        int &device = *machinePr; // 將device作為machineAPr的值的reference
        printf("value of pointer before reassign:%d\n", *machinePr);
        printf("device before reassign pointer:%d\n", device);
        printf("machineA before reassign pointer:%d\n\n", machineA);
        machinePr = &machineB;
        printf("value of pointer before reassign:%d\n", *machinePr);
        printf("device after reassign pointer:%d\n", device);
        printf("machineA before reassign pointer:%d\n", machineA);
    }

### *reference與函數參數*
----
reference最常用於函數參數，函數在運行的時候，會在函數中產生一個reference變數refer到引入的參數，這種傳遞引數的方法稱為`reference傳遞（passing by reference）`。

在C語言裡，只允許`值傳遞（passing by value）`，傳遞進函數的是值的副本，函數不能存取參數的原值，得透過傳遞指標的方式避開這個限制。

而C++則加入了reference傳遞的功能，使得函數可以處理原始資料