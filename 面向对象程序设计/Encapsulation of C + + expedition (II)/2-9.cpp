//
// Created by alex on 2019/12/15.
//

#include <iostream>

using namespace std;

class Coordinate {

public:
    Coordinate() {
    }

    // ��ӡ����ĺ���
    void printInfo() {
        cout << "(" << m_iX << "," << m_iY << ")" << endl;
    }

public:
    int m_iX;
    int m_iY;
};

int main(void) {
    //�����������
    Coordinate coorArr[2];
    coorArr[0].m_iX = 1;
    coorArr[0].m_iY = 2;
    coorArr[1].m_iX = 3;
    coorArr[1].m_iY = 4;

    //�������飬��ӡ������Ϣ
    for (int i = 0; i < 2; i++) {
        coorArr[i].printInfo();
    }
    return 0;
}