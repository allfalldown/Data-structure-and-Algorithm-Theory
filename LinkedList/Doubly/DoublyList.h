#pragma once
#include <iostream>

using namespace std;

struct Node{
    int info;
    Node *pNext;
    Node *pPrev;
};

struct List{
    Node *pHead;
    Node *pTail;
};

void Init(List &l);
Node *GetNode(int x);
void AddHead(List &l, Node *p);
void AddTail(List &l, Node *p);
void RemoveHead(List &l);
void RemoveTail(List &l);
void Input(List &l);
void Output(List &l);
