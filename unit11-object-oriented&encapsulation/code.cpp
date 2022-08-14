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