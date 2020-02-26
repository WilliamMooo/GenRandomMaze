#include "linkNode.h"

class Stack
{
private:
    linkNode* s;
public:
    bool isEmpty(); // 判断栈是否为空
    void push(elemType e); // 进栈
    elemType pop(); // 出栈
    void showStack(); // 显示栈内元素
    Stack();
    ~Stack();
};