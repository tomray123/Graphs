#include <QtCore/QCoreApplication>
#include <iostream>
#include <queue>

using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    queue<int> q; //Очередь для хранения вершин графа
    int mas[5][5] = //Матрица смежности
    {{0, 1, 0, 1, 1},
     {1, 0, 0, 1, 1},
     {0, 0, 0, 1, 0},
     {1, 1, 1, 0, 1},
     {1, 1, 0, 1, 0}};

    int nodes[5]; //Массив значений вершин
    for(int i = 0; i < 5; i++)
        nodes[i] = 0; //Изначально все вершины не посещенные (0)
    q.push(0); //Заносим первую вешину в очередь
    while(!q.empty()) //Пока очередь не пуста
    {
        int numb = q.front(); //Извлекаем вершину
        q.pop();
        nodes[numb] = 1; //Помечаем вешину, как пройденную
        for (int j = 0; j < 5; j++) //Проверка всех смежных вершин
            if(mas[numb][j] == 1 && nodes[j] == 0) //Если вершина смежная и при этом не посещенная
            {
                q.push(j); //Вершина заносится в очередь
                nodes[j] = 1; //И помечается, как пройденная
            }
        cout << numb + 1 << endl; //Вывод пройденных вершин
    }
    return a.exec();
}
