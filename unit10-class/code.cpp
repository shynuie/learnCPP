#include <iostream>
#include <string>

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