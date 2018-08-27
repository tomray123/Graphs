#include <QtCore/QCoreApplication>
#include <iostream>
#include <stack>

using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    stack<int> st; //���� ��� �������� ������ �����
    int mas[5][5] = //������� ���������
    {{0, 1, 0, 1, 1},
     {1, 0, 0, 1, 1},
     {0, 0, 0, 0, 1},
     {1, 1, 0, 0, 1},
     {1, 1, 1, 1, 0}};

    int nodes[5]; //������ �������� ������
    for(int i = 0; i < 5; i++)
        nodes[i] = 0; //���������� ��� ������� �� �������� (0)
    st.push(0); //������� ������ ������ � ����
    while(!st.empty()) //���� ���� �� ����
    {
        int numb = st.top(); //��������� �������
        st.pop();
        if (nodes[numb] == 2) //�������� �� �����
            continue;
        nodes[numb] = 2; //�������� �������, ��� ����������
        for (int j = 4; j >= 0; j--) //�������� ���� ������� ������
            if (mas[numb][j] == 1 && nodes[j] != 2) //���� ������� ������� � ��� ���� �� ����������
                st.push(j); //������� ������� � ����
        cout << numb + 1 << endl; //����� ���������� ������
    }

    return a.exec();
}
