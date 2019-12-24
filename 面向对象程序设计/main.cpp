#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <curses.h>

#pragma warning(disable : 4996)
using namespace std;

class student//����ѧ����
{
private:
    char name[20];//����
    char sex[5];//�Ա�
    int number;//ѧ��
    string major;//רҵ
    string Class;//�༶
    int score[3];//�ɼ�
    int total;//�ܳɼ�
    double average;//ƽ����

public:
    student();//���캯��
    void add();//�����Ϣ
    void output();//�����Ϣ
    void find();//������Ϣ
    void modify();//�޸���Ϣ
    void deleted();//ɾ����Ϣ
    void sort();//����
    void save();//����
    void load();//��ȡ��Ϣ
    student &operator=(student &T);//"="����
    friend istream &operator>>(istream &scin, student &s1);//">>"����
    friend ostream &operator<<(ostream &scout, student &s2);//"<<"����
};

student stu[1000];
int n = 0;//???

void student::add()  //��Ӻ���
{
    char flag = 'Y';
    while (toupper(flag) == 'Y') {
        cin >> stu[n];
        n++;
        cout << "Ҫ���������Y/N����" << endl;
        cin >> flag;
        if (toupper(flag) != 'Y') {
            if (toupper(flag) == 'N') {
                break;
            } else {
                cout << "�������������룺";
                cin >> flag;
            }
        }
    }
    cout << "�����������������" << endl;
}

void student::output()   //�������
{
    if (n != 0) {
        cout << "------------------------------\n";
        cout << setw(6) << "ѧ��" << setw(10) << "�༶" << setw(10) << "����" << setw(8) << "רҵ" << setw(10) << "�Ա�"
             << setw(8)
             << "�����ɼ�" << setw(7) << "C++�ɼ�" << setw(9) << "Ӣ��ɼ�" << setw(10)
             << "�ܳɼ�" << setw(12) << "ƽ���ɼ�" << endl;
        cout << "------------------------------\n";
        for (int t = 0; t < n; t++) {
            cout << stu[t];
        }
    }
    cout << "�����������������" << endl;
    getch();
}

void student::find()   //���Һ���
{
    int f3 = 0;
    char n1[20];
    student temp;
    cout << "��������Ҫ���ҵ��˵�������";
    cin >> n1;
    for (int j = 0; j < n; j++) {
        if (strcmp(stu[j].name, n1) == 0) {
            temp = stu[j];
            f3 = 1;
        }
    }
    if (f3 == 0) {
        cout << "�Բ���û���ҵ���Ҫ���ҵ�ѧ����Ϣ" << endl;
    } else {
        cout << " ---------------------------------------------------------------------------\n";
        cout << " number name sex math C++ English total average\n";
        cout << " ---------------------------------------------------------------------------\n";
        cout << " " << temp.number << " " << temp.Class << " " << temp.name << " " << temp.major << " " << temp.sex
             << " " << temp.score[0]
             << " " << temp.score[1] << " " << temp.score[2] << " " << temp.total << " " << temp.average << endl;
    }
    cout << "�����������������" << endl;
    getch();
}

void student::modify()   //�޸ĺ���
{
    int f4 = 0;
    int t;
    char n2[20];
    cout << "��������Ҫ�޸ĵ��˵�������";
    cin >> n2;
    for (int j = 0; j < n; j++) {
        if (strcmp(stu[j].name, n2) == 0) {
            t = j;
            f4 = 1;
        }
    }
    if (f4 == 0) {
        cout << "�Բ���û����Ҫ�޸ĵ�ѧ���ɼ�" << endl;
    } else {
        cout << "������ѧ�ţ�";
        cin >> stu[t].number;
        cout << "�༶��";
        cin >> stu[t].Class;
        cout << "������";
        cin >> stu[t].name;
        cout << "רҵ��";
        cin >> stu[t].major;
        cout << "�Ա�";
        cin >> stu[t].sex;
        cout << "�����ɼ���";
        cin >> stu[t].score[0];
        cout << "C++�ɼ���";
        cin >> stu[t].score[1];
        cout << "Ӣ��ɼ���";
        cin >> stu[t].score[2];
        stu[t].total = stu[t].score[0] + stu[t].score[1] + stu[t].score[2];
        stu[t].average = stu[t].total / 3;
        cout << "�޸ĳɹ���" << endl;
    }
    cout << "�����������������" << endl;
    getch();
}

void student::deleted()   //ɾ������
{
    char c;
    char n3[20];
    bool f5 = false;
    do {
        cout << "������Ҫɾ����ѧ��������";
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
            cout << "��Ҫɾ����ѧ�������ڣ�" << endl;

        cout << "��Ҫ����ɾ����(Y/N)" << endl;
        cin >> c;
        if (toupper(c) != 'Y' && toupper(c) != 'N') {
            cout << "����ָ���������������Y��N��" << endl;
            cin >> c;
        }
    } while (toupper(c) == 'Y');
    cout << "�����������������" << endl;
    getch();
}

void student::sort()   //������
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
    cout << "\n\n����ɹ���\n\n";
}

void student::save()   //���溯��
{
    char filename1[20];
    cout << "�������ļ�����";
    cin >> filename1;
    ofstream fout(filename1, ios::app);
    if (!fout)cout << "�ļ����ܴ򿪣�" << endl;
    else {
        for (int i = 0; i < n; i++) {
            fout << " " << stu[i].number << " " << stu[i].Class << " " << stu[i].name << " " << stu[i].major << " "
                 << stu[i].sex << " " << stu[i].score[0] << " " << stu[i].score[1] << " " << stu[i].score[2] << " "
                 << stu[i].total << " " << stu[i].average << endl;
            cout << "����ɹ���" << endl;
        }
        fout.close();
    }
    cout << "�����������������" << endl;
    getch();
}


void student::load()    //��ȡ����
{
    char filenname2[20];
    cout << "��������Ҫ��ȡ���ļ�����";
    cin >> filenname2;
    ifstream fin(filenname2, ios::in);
    if (!fin)cout << "�ļ��򲻿���" << endl;
    else {
        for (int i = 0;; i++, n = i - 1) {
            if (fin.eof())break;
            fin >> stu[i].number >> stu[i].Class >> stu[i].name >> stu[i].major >> stu[i].sex >> stu[i].score[0]
                >> stu[i].score[1] >> stu[i].score[2] >> stu[i].total >> stu[i].average;
        }
        cout << "�ļ��Ѷ�ȡ�ɹ���" << endl;
    }
    fin.close();
    cout << "�����������������" << endl;
    getch;
}

student &student::operator=(student &T)   //����=
{
    strcpy(name, T.name);
    strcpy(sex, T.sex);
    number = T.number;
    for (int i = 0; i < 3; i++)score[i] = T.score[i];
    total = T.total;
    average = T.average;
    return (*this);
}

ostream &operator<<(ostream &scout, student &s2)//����<<
{
    cout << setw(6) << s2.number << setw(10) << s2.Class << setw(10) << s2.name << setw(8) << s2.major << setw(10)
         << s2.sex << setw(8)
         << s2.score[0] << setw(7) << s2.score[1] << setw(9) << s2.score[2] << setw(10)
         << s2.total << setw(12) << s2.average << endl;
    return scout;
}

istream &operator>>(istream &scin, student &s1)//����>>
{
    cout << "\tѧ��:";
    scin >> s1.number;
    cout << "\t�༶:";
    scin >> s1.Class;
    cout << "\t����:";
    scin >> s1.name;
    cout << "\tרҵ:";
    scin >> s1.major;
    cout << "\t�Ա�:";
    scin >> s1.sex;
    cout << "\t�����ɼ�:";
    scin >> s1.score[0];
    cout << "\tC++�ɼ�:";
    scin >> s1.score[1];
    cout << "\tӢ��ɼ�:";
    scin >> s1.score[2];
    s1.total = s1.score[0] + s1.score[1] + s1.score[2];
    s1.average = s1.total / 3;
    return scin;
}

student::student()//���캯��
{
    strcpy(name, "");
    strcpy(sex, "");
    number = 0;
    for (int i = 0; i < 3; i++)score[i] = 0;
    total = 0;
    average = 0;
}

void menu()                                                         //�˵�����
{
    cout << "  ��������������ѧ���ɼ�����ϵͳ�������������� " << endl;
    cout << " |                                            |" << endl;
    cout << " |                                            |" << endl;
    cout << " |     ============ ���ܲ˵� ============     |" << endl;
    cout << " |                                            |" << endl;
    cout << " |             0 �˳�ϵͳ                     |" << endl;
    cout << " |                                            |" << endl;
    cout << " |             1 ���ѧ���ɼ���Ϣ             |" << endl;
    cout << " |                                            |" << endl;
    cout << " |             2 ���ѧ���ɼ���Ϣ             |" << endl;
    cout << " |                                            |" << endl;
    cout << " |             3 ����ѧ���ɼ���Ϣ             |" << endl;
    cout << " |                                            |" << endl;
    cout << " |             4 �޸�ѧ���ɼ���Ϣ             |" << endl;
    cout << " |                                            |" << endl;
    cout << " |             5 ɾ��ѧ���ɼ���Ϣ             |" << endl;
    cout << " |                                            |" << endl;
    cout << " |             6 ѧ���ɼ���Ϣ����             |" << endl;
    cout << " |                                            |" << endl;
    cout << " |             7 ��������                     |" << endl;
    cout << " |                                            |" << endl;
    cout << " |             8 ��������                     |" << endl;
    cout << " |                                            |" << endl;
    cout << " |                                            |" << endl;
    cout << "  �������������������������������������������� " << endl;
    cout << "����ѡ��0-8�������س���ȷ��: ";
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