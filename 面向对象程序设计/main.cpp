#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <curses.h>

#pragma warning(disable : 4996)
using namespace std;

class student//定义学生类
{
private:
    char name[20];//姓名
    char sex[5];//性别
    int number;//学号
    string major;//专业
    string Class;//班级
    int score[3];//成绩
    int total;//总成绩
    double average;//平均分

public:
    student();//构造函数
    void add();//添加信息
    void output();//输出信息
    void find();//查找信息
    void modify();//修改信息
    void deleted();//删除信息
    void sort();//排序
    void save();//保存
    void load();//读取信息
    student &operator=(student &T);//"="重载
    friend istream &operator>>(istream &scin, student &s1);//">>"重载
    friend ostream &operator<<(ostream &scout, student &s2);//"<<"重载
};

student stu[1000];
int n = 0;//???

void student::add()  //添加函数
{
    char flag = 'Y';
    while (toupper(flag) == 'Y') {
        cin >> stu[n];
        n++;
        cout << "要继续添加吗（Y/N）？" << endl;
        cin >> flag;
        if (toupper(flag) != 'Y') {
            if (toupper(flag) == 'N') {
                break;
            } else {
                cout << "错误，请重新输入：";
                cin >> flag;
            }
        }
    }
    cout << "按任意键返回主界面" << endl;
}

void student::output()   //输出函数
{
    if (n != 0) {
        cout << "------------------------------\n";
        cout << setw(6) << "学号" << setw(10) << "班级" << setw(10) << "姓名" << setw(8) << "专业" << setw(10) << "性别"
             << setw(8)
             << "高数成绩" << setw(7) << "C++成绩" << setw(9) << "英语成绩" << setw(10)
             << "总成绩" << setw(12) << "平均成绩" << endl;
        cout << "------------------------------\n";
        for (int t = 0; t < n; t++) {
            cout << stu[t];
        }
    }
    cout << "按任意键返回主界面" << endl;
    getch();
}

void student::find()   //查找函数
{
    int f3 = 0;
    char n1[20];
    student temp;
    cout << "请输入你要查找的人的姓名：";
    cin >> n1;
    for (int j = 0; j < n; j++) {
        if (strcmp(stu[j].name, n1) == 0) {
            temp = stu[j];
            f3 = 1;
        }
    }
    if (f3 == 0) {
        cout << "对不起，没有找到你要查找的学生信息" << endl;
    } else {
        cout << " ---------------------------------------------------------------------------\n";
        cout << " number name sex math C++ English total average\n";
        cout << " ---------------------------------------------------------------------------\n";
        cout << " " << temp.number << " " << temp.Class << " " << temp.name << " " << temp.major << " " << temp.sex
             << " " << temp.score[0]
             << " " << temp.score[1] << " " << temp.score[2] << " " << temp.total << " " << temp.average << endl;
    }
    cout << "按任意键返回主界面" << endl;
    getch();
}

void student::modify()   //修改函数
{
    int f4 = 0;
    int t;
    char n2[20];
    cout << "请输入你要修改的人的姓名：";
    cin >> n2;
    for (int j = 0; j < n; j++) {
        if (strcmp(stu[j].name, n2) == 0) {
            t = j;
            f4 = 1;
        }
    }
    if (f4 == 0) {
        cout << "对不起，没有你要修改的学生成绩" << endl;
    } else {
        cout << "请输入学号：";
        cin >> stu[t].number;
        cout << "班级：";
        cin >> stu[t].Class;
        cout << "姓名：";
        cin >> stu[t].name;
        cout << "专业：";
        cin >> stu[t].major;
        cout << "性别：";
        cin >> stu[t].sex;
        cout << "高数成绩：";
        cin >> stu[t].score[0];
        cout << "C++成绩：";
        cin >> stu[t].score[1];
        cout << "英语成绩：";
        cin >> stu[t].score[2];
        stu[t].total = stu[t].score[0] + stu[t].score[1] + stu[t].score[2];
        stu[t].average = stu[t].total / 3;
        cout << "修改成功！" << endl;
    }
    cout << "按任意键返回主界面" << endl;
    getch();
}

void student::deleted()   //删除函数
{
    char c;
    char n3[20];
    bool f5 = false;
    do {
        cout << "请输入要删除的学生姓名：";
        cin >> n3;
        for (int i = 0; i < n; i++) {
            if (strcmp(n3, stu[i].name) == 0) {
                f5 = true;
                n--;
                do {
                    stu[i] = stu[i + 1];
                    i++;
                } while (i <= n);
            }
        }

        if (!f5)
            cout << "您要删除的学生不存在！" << endl;

        cout << "您要继续删除吗？(Y/N)" << endl;
        cin >> c;
        if (toupper(c) != 'Y' && toupper(c) != 'N') {
            cout << "输入指令错误！请重新输入Y或N！" << endl;
            cin >> c;
        }
    } while (toupper(c) == 'Y');
    cout << "按任意键返回主界面" << endl;
    getch();
}

void student::sort()   //排序函数
{
    int i, j, k;
    student s3;
    for (i = 0; i < (n - 1); i++) {
        k = i;
        for (j = i + 1; j < n; j++)
            if (stu[j].average > stu[i].average)
                k = j;
        if (k != i) {
            s3 = stu[i];
            stu[i] = stu[k];
            stu[k] = s3;
        }
    }
    cout << "-------------------------------------------------------------------------\n";
    cout << "number      name     sex    math    C++    English     total     average" << endl;
    cout << "-------------------------------------------------------------------------\n";
    for (int t = 0; t < n; t++) {
        cout << stu[t];
    }
    cout << "\n\n排序成功！\n\n";
}

void student::save()   //保存函数
{
    char filename1[20];
    cout << "请输入文件名：";
    cin >> filename1;
    ofstream fout(filename1, ios::app);
    if (!fout)cout << "文件不能打开！" << endl;
    else {
        for (int i = 0; i < n; i++) {
            fout << " " << stu[i].number << " " << stu[i].Class << " " << stu[i].name << " " << stu[i].major << " "
                 << stu[i].sex << " " << stu[i].score[0] << " " << stu[i].score[1] << " " << stu[i].score[2] << " "
                 << stu[i].total << " " << stu[i].average << endl;
            cout << "保存成功！" << endl;
        }
        fout.close();
    }
    cout << "按任意键返回主界面" << endl;
    getch();
}


void student::load()    //读取函数
{
    char filenname2[20];
    cout << "请输入你要读取的文件名：";
    cin >> filenname2;
    ifstream fin(filenname2, ios::in);
    if (!fin)cout << "文件打不开！" << endl;
    else {
        for (int i = 0;; i++, n = i - 1) {
            if (fin.eof())break;
            fin >> stu[i].number >> stu[i].Class >> stu[i].name >> stu[i].major >> stu[i].sex >> stu[i].score[0]
                >> stu[i].score[1] >> stu[i].score[2] >> stu[i].total >> stu[i].average;
        }
        cout << "文件已读取成功！" << endl;
    }
    fin.close();
    cout << "按任意键返回主界面" << endl;
    getch;
}

student &student::operator=(student &T)   //重载=
{
    strcpy(name, T.name);
    strcpy(sex, T.sex);
    number = T.number;
    for (int i = 0; i < 3; i++)score[i] = T.score[i];
    total = T.total;
    average = T.average;
    return (*this);
}

ostream &operator<<(ostream &scout, student &s2)//重载<<
{
    cout << setw(6) << s2.number << setw(10) << s2.Class << setw(10) << s2.name << setw(8) << s2.major << setw(10)
         << s2.sex << setw(8)
         << s2.score[0] << setw(7) << s2.score[1] << setw(9) << s2.score[2] << setw(10)
         << s2.total << setw(12) << s2.average << endl;
    return scout;
}

istream &operator>>(istream &scin, student &s1)//重载>>
{
    cout << "\t学号:";
    scin >> s1.number;
    cout << "\t班级:";
    scin >> s1.Class;
    cout << "\t姓名:";
    scin >> s1.name;
    cout << "\t专业:";
    scin >> s1.major;
    cout << "\t性别:";
    scin >> s1.sex;
    cout << "\t高数成绩:";
    scin >> s1.score[0];
    cout << "\tC++成绩:";
    scin >> s1.score[1];
    cout << "\t英语成绩:";
    scin >> s1.score[2];
    s1.total = s1.score[0] + s1.score[1] + s1.score[2];
    s1.average = s1.total / 3;
    return scin;
}

student::student()//构造函数
{
    strcpy(name, "");
    strcpy(sex, "");
    number = 0;
    for (int i = 0; i < 3; i++)score[i] = 0;
    total = 0;
    average = 0;
}

void menu()                                                         //菜单界面
{
    cout << "  ———————学生成绩管理系统——————— " << endl;
    cout << " |                                            |" << endl;
    cout << " |                                            |" << endl;
    cout << " |     ============ 功能菜单 ============     |" << endl;
    cout << " |                                            |" << endl;
    cout << " |             0 退出系统                     |" << endl;
    cout << " |                                            |" << endl;
    cout << " |             1 添加学生成绩信息             |" << endl;
    cout << " |                                            |" << endl;
    cout << " |             2 输出学生成绩信息             |" << endl;
    cout << " |                                            |" << endl;
    cout << " |             3 查找学生成绩信息             |" << endl;
    cout << " |                                            |" << endl;
    cout << " |             4 修改学生成绩信息             |" << endl;
    cout << " |                                            |" << endl;
    cout << " |             5 删除学生成绩信息             |" << endl;
    cout << " |                                            |" << endl;
    cout << " |             6 学生成绩信息排序             |" << endl;
    cout << " |                                            |" << endl;
    cout << " |             7 保存数据                     |" << endl;
    cout << " |                                            |" << endl;
    cout << " |             8 读出数据                     |" << endl;
    cout << " |                                            |" << endl;
    cout << " |                                            |" << endl;
    cout << "  —————————————————————— " << endl;
    cout << "输入选择（0-8）并按回车键确认: ";
}

int main() {
    int choose;
    student s;
    do {
        menu();
        cin >> choose;
        switch (choose) {
            case 1:
                s.add();
                //system("pause");
                system("cls");
                break;
            case 2:
                s.output();
                system("cls");
                break;
            case 3:
                s.find();
                system("cls");
                break;
            case 4:
                s.modify();
                break;
            case 5:
                s.deleted();
                system("cls");
                break;
            case 6:
                s.sort();
                system("cls");
                break;
            case 7:
                s.save();
                system("cls");
                break;
            case 8:
                s.load();
                system("cls");
                break;
            default:
                break;
        }
    } while (choose != 0);
}