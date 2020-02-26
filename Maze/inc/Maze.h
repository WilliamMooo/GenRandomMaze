#include "Grid.h"

class Maze
{
private:
    int Columns;
    int Rows;
    Grid **g;
public:
    void initGrid(); // 初始化网格
    int randomNum(int min, int max); // 返回大小在min和max范围内的随机数
    void DFS(); // 深度优先遍历生成迷宫
    void drawMaze(); // 画出迷宫
    Maze();
    Maze(int c, int r);
    ~Maze();
};