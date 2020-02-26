#include <iostream>

#include "Maze.h"

using namespace std;

int main() {
    int columns, rows;
    while (true) {
        system("cls");
        cout << "请输入迷宫的规模(长,宽):";
        cin >> columns >> rows;
        Maze *m = new Maze(columns, rows);
        m->drawMaze();
        delete m;
        system("pause");
    }
    return 0;
}