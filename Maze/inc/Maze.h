#include "Grid.h"

class Maze
{
private:
    int Columns;
    int Rows;
    Grid **g;
public:
    void initGrid(); // ��ʼ������
    int randomNum(int min, int max); // ���ش�С��min��max��Χ�ڵ������
    void DFS(); // ������ȱ��������Թ�
    void drawMaze(); // �����Թ�
    Maze();
    Maze(int c, int r);
    ~Maze();
};