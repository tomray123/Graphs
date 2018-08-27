#include <QtCore/QCoreApplication>
#include <iostream>
#include <queue>

using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    queue<int> q; //������� ��� �������� ������ �����
    int mas[5][5] = //������� ���������
    {{0, 1, 0, 1, 1},
     {1, 0, 0, 1, 1},
     {0, 0, 0, 1, 0},
     {1, 1, 1, 0, 1},
     {1, 1, 0, 1, 0}};

    int nodes[5]; //������ �������� ������
    for(int i = 0; i < 5; i++)
        nodes[i] = 0; //���������� ��� ������� �� ���������� (0)
    q.push(0); //������� ������ ������ � �������
    while(!q.empty()) //���� ������� �� �����
    {
        int numb = q.front(); //��������� �������
        q.pop();
        nodes[numb] = 1; //�������� ������, ��� ����������
        for (int j = 0; j < 5; j++) //�������� ���� ������� ������
            if(mas[numb][j] == 1 && nodes[j] == 0) //���� ������� ������� � ��� ���� �� ����������
            {
                q.push(j); //������� ��������� � �������
                nodes[j] = 1; //� ����������, ��� ����������
            }
        cout << numb + 1 << endl; //����� ���������� ������
    }
    return a.exec();
}
