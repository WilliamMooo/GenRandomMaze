#include "linkNode.h"

class Stack
{
private:
    linkNode* s;
public:
    bool isEmpty(); // �ж�ջ�Ƿ�Ϊ��
    void push(elemType e); // ��ջ
    elemType pop(); // ��ջ
    void showStack(); // ��ʾջ��Ԫ��
    Stack();
    ~Stack();
};