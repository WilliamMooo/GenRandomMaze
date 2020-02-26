#include <iostream>

#include "Stack.h"
#include "Maze.h"

using namespace std;

Maze::Maze()
{
    Columns = 17;
    Rows = 23;
    initGrid();
    DFS();
}

Maze::Maze(int c, int r)
{
    Columns = c;
    Rows = r;
    initGrid();
    DFS();
}

void Maze::initGrid() {
    g = new Grid*[Columns];
    for (int i = 0; i < Columns; i++) g[i] = new Grid[Rows];
    for (int i = 0; i < Columns; i++) {
        for (int j = 0; j < Rows; j++) {
            g[i][j].x = i;
            g[i][j].y = j;
            if (i == 0 || j == 0 || i+1 == Columns || j+1 == Rows) { // �߽�
                g[i][j].isVisited = true;
                g[i][j].isConnected = false;
            } else if (i%2 == 0 || j%2 == 0) { // ǽ
                g[i][j].isVisited = false;
                g[i][j].isConnected = false;            
            } else { // ����ͨ������
                g[i][j].isVisited = false;
                g[i][j].isConnected = true;
            }
        }
    }
}

int Maze::randomNum(int min, int max) {
    return rand()%(max-min)+min;
}

void Maze::DFS() {
    Stack *st = new Stack();
    st->push(1);
    st->push(1);
    int direction[4] = {1, 2, 3, 4}; // 1,2,3,4�ֱ�������ϡ��ҡ���4������
    while (st->isEmpty() == false) {
        int y = st->pop();
        int x = st->pop();
        // ���ѡȡ4������, ����direction����
        int rand = randomNum(1,3);
        int temp = direction[rand];
        direction[rand] = direction[0];
        direction[0] = temp;
        temp = direction[1];
        direction[1] = direction[3];
        direction[3] = temp;
        // ������������
        for (int i = 0; i < 4; i++) {
            switch(direction[i]) {
                case 1: // ����������
                    if (x-2 > 0 && g[x-2][y].isVisited == false) {
                        g[x-2][y].isVisited = true;
                        st->push(x-2);
                        st->push(y);
                        g[x-1][y].isConnected = true;
                    }
                    break;
                case 2: // �����Ϸ�����
                    if (y-2 > 0 && g[x][y-2].isVisited == false) {
                        g[x][y-2].isVisited = true;
                        st->push(x);
                        st->push(y-2);
                        g[x][y-1].isConnected = true;
                    }
                    break;
                case 3: // �����ҷ�����
                    if (x+2 < Columns && g[x+2][y].isVisited == false) {
                        g[x+2][y].isVisited = true;
                        st->push(x+2);
                        st->push(y);
                        g[x+1][y].isConnected = true;
                    }
                    break;
                case 4: // �����·�����
                    if (y+2 < Rows && g[x][y+2].isVisited == false) {
                        g[x][y+2].isVisited = true;
                        st->push(x);
                        st->push(y+2);
                        g[x][y+1].isConnected = true;
                    }
                    break;
                default:
                    break;
            }
        }
    }
    // ȥ����Ե�����ǽ
    if (Columns%2 == 0) {
        for (int i = 1; i < Columns; i++) {
            if (g[Columns-3][i].isConnected == true) g[Columns-2][i].isConnected = true;
        }
    }
    if (Rows%2 == 0) {
        for (int i = 1; i < Rows; i++) {
            if (g[i][Rows-3].isConnected == true) g[i][Rows-2].isConnected = true;
        }
    }
}

void Maze::drawMaze() {
    for (int i = 0; i < Columns; i++) {
        for (int j = 0; j < Rows; j++) {
            if (g[i][j].isConnected == true) cout << "  ";
            else cout << "��";
        }
        cout << endl;
    }
}

Maze::~Maze()
{
    free(g);
}
