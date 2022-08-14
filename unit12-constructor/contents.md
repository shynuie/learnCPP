# Unit12 - 建構函數 constructor

## I. 多載函數
函數(function)可以針對不同種型態的參數(parameter)有多個版本，建構函數(constructor)也是。具有多個參數版本的函數被稱作多載函數(overloaded function)  

範例代碼：

    #include <iostream>


    int add(int arg1, int arg2);
    double add(double arg1, int arg2);

    int add(int arg1, int arg2){
        return (arg1 + arg2);
    }

    double add(double arg1, int arg2){
        return (arg1 + (double)arg2);
    }

    int main(void){
        printf("%d\n", add(2,3));
        printf("%f\n", add(2.0,3));
    }
----
## II.建構函數
建構函數的主要目的是設定資料成員(data member)。同樣的，我們可以針對多種參數形式，來設計不同種參數的建構方式。

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
            Teacher();  // 無參數的建構函數
            Teacher(int salary_);  // 有一參數的建構函數
            Teacher(int salary_, int rate_);  // 有兩參數的建構函數
            string name;
            string employee_id;
            int cal_bonus();
            int get_bonus_rate();
            void set_bonus_rate(int rate);
            void set_salary(int value);

        // 宣告 private 成員
        private:
            int bonus_rate;
            int salary;
    };

    // 實作建構函數
    Teacher::Teacher(){
        set_salary(35000);
        set_bonus_rate(2);
    }

    Teacher::Teacher(int salary_){
        set_salary(salary_);
    }

    Teacher::Teacher(int salary_, int rate_){
        set_salary(salary_);
        set_bonus_rate(rate_);
    }


    // 實作成員函數
    int Teacher::cal_bonus()
    {
        return (bonus_rate * salary);
    }

    void Teacher::set_bonus_rate(int rate){
        if (rate > 0){
            bonus_rate = rate;
        }
        else{
            bonus_rate = 0;
        }
    }

    void Teacher::set_salary(int value){
        if (value >= 0){
            salary = value;
        }
        else{
            salary = 0;
        }
    }

    // 主程式
    int main(void){
        Teacher marvin;
        marvin.name = "Marvin";
        marvin.employee_id = "001";
        int bonus_marvin = marvin.cal_bonus();
        cout << "Marvin bonus:" << bonus_marvin << endl;  // Marvin bonus:70000
        Teacher lily(40000, 3);
        int bonus_lily = lily.cal_bonus();
        cout << "Lily bonus:" << bonus_lily << endl;  // Lily bonus:120000
    }

給定參數利用建構函數建立物件時加小括弧即可，需要留意`沒有參數的建構函數不需要加小括弧`。