#include <QtCore/QCoreApplication>
#include <iostream>
#include <stack>

using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    stack<int> st; //Стек для хранения вершин графа
    int mas[5][5] = //Матрица смежности
    {{0, 1, 0, 1, 1},
     {1, 0, 0, 1, 1},
     {0, 0, 0, 0, 1},
     {1, 1, 0, 0, 1},
     {1, 1, 1, 1, 0}};

    int nodes[5]; //Массив значений вершин
    for(int i = 0; i < 5; i++)
        nodes[i] = 0; //Изначально все вершины не посещены (0)
    st.push(0); //Заносим первую вешину в стек
    while(!st.empty()) //Пока стек не пуст
    {
        int numb = st.top(); //Извлекаем вершину
        st.pop();
        if (nodes[numb] == 2) //Проверка на тупик
            continue;
        nodes[numb] = 2; //Помечаем вершину, как пройденную
        for (int j = 4; j >= 0; j--) //Проверка всех смежных вершин
            if (mas[numb][j] == 1 && nodes[j] != 2) //Если вершина смежная и при этом не посещенная
                st.push(j); //Заносим вершину в стек
        cout << numb + 1 << endl; //Вывод пройденных вершин
    }

    return a.exec();
}
