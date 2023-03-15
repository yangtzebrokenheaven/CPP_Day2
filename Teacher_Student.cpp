#include <iostream>
#include <string>
using namespace std;

struct student
{
    string aname;
    int score;
};
struct teacher
{
    string tname;
    struct student arry1[5];
};
void insert_score(teacher arry[], int len)
{
    string nameseed = "ABCDE";
    for (int i = 0; i < len; i++)
    {
        arry[i].tname = "Teacher_";
        arry[i].tname += nameseed[i];
        for (int j = 0; j < 5; j++)
        {
            arry[i].arry1[j].aname = "Student_";
            arry[i].arry1[j].aname += nameseed[j];
            arry[i].arry1[j].score = 60;
        }
    }
}
void print(teacher arry[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << "老师姓名：" << arry[i].tname << endl;
        for (int j = 0; j < 5; j++)
        {
            cout << "学生姓名：" << arry[i].arry1[j].aname << arry[i].arry1[j].score << endl;
        }
    }
}
int main()
{
    teacher arry[3];
    student arry1[5];
    int len = sizeof(arry) / sizeof(arry[0]);
    insert_score(arry, len);
    print(arry, len);
    return 0;
}