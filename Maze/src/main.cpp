#include <iostream>

#include "Maze.h"

using namespace std;

int main() {
    int columns, rows;
    while (true) {
        system("cls");
        cout << "�������Թ��Ĺ�ģ(��,��):";
        cin >> columns >> rows;
        Maze *m = new Maze(columns, rows);
        m->drawMaze();
        delete m;
        system("pause");
    }
    return 0;
}