//
// Created by alex on 2019/12/15.
//

#include <iostream>
#include <string>
using namespace std;
/**
 * �����ࣺStudent
 * ���ݳ�Ա��m_strName
 * �޲ι��캯����Student()
 * �вι��캯����Student(string _name)
 * �������캯����Student(const Student& stu)
 * ����������~Student()
 * ���ݳ�Ա������setName(string _name)��getName()
 */

class Student{
private:
    string m_strName;
public:
    Student();
    Student(string _name);
    Student(const Student& stu);
    ~Student();
    void setName(string _name){m_strName = _name;};
    string getNAme(){return m_strName;};
};

Student::Student() {

}

Student::Student(string _name) {
    m_strName = _name;
}

Student::Student(const Student &stu) {

}

Student::~Student() {

}

int main(void)
{
    // ͨ��new��ʽʵ��������*stu
    Student *stu = new Student;
    // ���Ķ�������ݳ�ԱΪ��Ľ������
    stu->setName("Ľ����");
    // ��ӡ��������ݳ�Ա
    cout << stu->getNAme() << endl;
    return 0;
}