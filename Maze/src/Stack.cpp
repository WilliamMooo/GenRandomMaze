#include <iostream>

#include "Stack.h"

using namespace std;

Stack::Stack() {
    s = (linkNode*)malloc(sizeof(linkNode));
    s->next = NULL;
}

Stack::~Stack() {
    linkNode *pre = s, *p = s->next;
    while (p != NULL) {
        free(pre);
        pre = p;
        p = p->next;
    }
    free(pre);
}

bool Stack::isEmpty() {
    return (s->next == NULL);
}

void Stack::push(elemType e) {
    linkNode *p = (linkNode*)malloc(sizeof(linkNode));
    p->data = e;
    p->next = s->next;
    s->next = p;
}

elemType Stack::pop() {
    linkNode *p;
    p = s->next;
    elemType e = p->data;
    s->next = p->next;
    free(p);
    return e;
}

void Stack::showStack() {
    linkNode *p = s->next;
    while (p != NULL) {
        cout << p->data << endl;
        p = p->next;
    }
    free(p);
}