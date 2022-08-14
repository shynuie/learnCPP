# Unit11 - 物件導向與封裝 object-oriented and encapsulation

物件導向程式設計(object-oriented programming)有三大基本特性，分別是：
* 繼承（inheritance）
* 封裝（encapsulation）
* 多型（polymorphism）

----
## I. 繼承 Inheritance

繼承的目的是讓類別（class）具有類似親屬的垂直關係（父母vs子女），子類別（subclass）可以擁有父類別（superclass）的成員（資料、函數，父母有的屬性子女也有，父母會的方法子女也會。）

例如：
    `主任`類別繼承了`教職員`類別，這時`教職員`為父類別，`主任`則為子類別。`教職員`的公開屬性：`職員編號`、`職員姓名`...等，`主任`類別也會有，`教職員`的公開函數：`開早會`、`寫週報`...等，`主任`類別也會有。

----
## II. 多型 Polymorphism

多個子類別繼承相同的父類別時，我們就可以用父類別來同時表示這些子類別

例如：
    假設`教職員`這個父類別同時擁有子類別：`主任`、`校長`，當我們想用一個類別來表示`主任`、`校長`跟`一般教職員`時，我們就直接以`教職員`來統稱即可。打個比方，如果今天我們在會議室內，想要廣播通知主任、校長跟一般教職員來開會時，我們不需要說`請校長、主任與一般教職員來會議室開會`，我們只需要說`請教職員來會議室開會`即可。

----
## III. 封裝 Encapsulation

封裝是指我們將資料封在類別裡，這還牽涉到程式設計中另一個重要的概———資訊隱藏（information hiding），目的是不讓外界隨意存取類別的資料，只允許類別的成員函數存取類別的資料成員(data member)。這時候就可以利用存取標籤(access label)`private`了。

例如：
    在前個例子裡，假設學校每年底會發放年終獎金一次，獎金的額度取決於職位的薪資(salary)與獎金乘數(bonus rate)，這時我們就可以在父類別`教職員`裡，增加`private`資料成員：`薪資`與`獎金乘數`，然後新增一個`public`的成員函數`計算獎金`用作計算每個職位的獎金金額。在`計算獎金`的計算過程中，這個成員函數會存取類別內部的`薪資`與`獎金乘數`資料成員來計算實際獎金金額。這樣每到年底時，我們僅需調用各個物件的`計算獎金`，就能計算出年終獎金，而不需要知道該職等的實際薪資與獎金乘數是多少，對於資訊隱藏起到了一定的效果。

範例代碼：

    #include <iostream>
    #include <string>

    using namespace std;

    class Teacher{
        /*
        Class for employee in school.
        */

        // 宣告 public 成員
        public:
            string name;
            string employee_id;
            int cal_bonus();

        // 宣告 private 成員
        private:
            int bonus_rate = 2;
            int salary = 35000;
    };

    // 實作函數
    int Teacher::cal_bonus()
    {
        return (bonus_rate * salary);
    }

    // 主程式
    int main(void){
        Teacher marvin;
        marvin.name = "Marvin";
        marvin.employee_id = "001";
        int bonus = marvin.cal_bonus();
        cout << "bonus:" << bonus << endl;
    }

## IV. Getter & Setter

由於`private`的資料成員僅能被成員函數存取，所以我們通常會額外設計`public`的成員函數來進行資料的存——setter(以set字樣開頭) 和 取——getter(以get字樣開頭)。這樣的好處是，在取的時候，可以選擇給予資料的副本，避免外部在使用的時候，意外更改到物件內的原資料；而存的時候，則可以對欲存的資料進行檢查，避免將錯誤的資料型態、格式、數值存到物件內。

範例代碼：
    #include <iostream>
    #include <string>

    using namespace std;

    class Teacher{
        /*
        Class for employee in school.
        */

        // 宣告 public 成員
        public:
            string name;
            string employee_id;
            int cal_bonus();
            int get_bonus_rate();
            void set_bonus_rate(int rate);

        // 宣告 private 成員
        private:
            int bonus_rate = 2;
            int salary = 35000;
    };

    // 實作函數
    int Teacher::cal_bonus()
    {
        return (bonus_rate * salary);
    }

    int Teacher::get_bonus_rate(){
        return bonus_rate;
    }

    void Teacher::set_bonus_rate(int rate){
        if (rate > 0){
            bonus_rate = rate;
        }
    }

    // 主程式
    int main(void){
        Teacher marvin;
        marvin.name = "Marvin";
        marvin.employee_id = "001";
        int bonus = marvin.cal_bonus();
        cout << "bonus:" << bonus << endl;
        cout << "bonus rate:" << marvin.get_bonus_rate() << endl;
    }

如果每個資料成員都得在物件宣告時，一一透過setter來設值，是很麻煩的，有時候我們希望這些資料成員具有預設值，這時候我們就需要使用構建函數了，在下個章節會介紹。