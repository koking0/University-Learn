//
// Created by alex on 2019/12/2.
//

#include <iostream>

using namespace std;

class Student{
    int num, age;
    float score;
    static int count;
    static float sum;

public:
    Student(int n, int a, float s):num(n), age(a),score(s){}
    void total();
    static float average();
};

void Student::total(){
    sum += score;
    count++;
}

float Student::average() {
    return sum / count;
}

float Student::sum = 0;
int Student::count = 0;

int main(){
    Student stu[5] = {
            Student(1000, 18, 93),
            Student(1001, 19, 67),
            Student(1002, 19, 79),
            Student(1003, 20, 82),
            Student(1004, 18, 62)
    };

    int n;
    cout << "请输入学生个数：";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        stu[i].total();
    }
    cout << n << "位同学的平均成绩为：" << Student::average() << endl;
    return 0;
}