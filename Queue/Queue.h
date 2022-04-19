#pragma once
#include <iostream>
using namespace std;

// thanh phan cua 1 node, neu info can nhieu thong tin thi luu trong 1 struct khac
struct Node{ 
    int info;
    Node *pNext;
};

//thanh phan cua list
struct Queue{
    Node *pHead;
    Node *pTail;
};

//thao tac mac dinh
void Init(Queue &s); //khoi tao danh sach
Node *GetNode(int x); //vi du su dung node luu 1 gia tri duy nhat, luu y dau *, Node co kieu tra ve la pointer
bool IsEmpty(Queue s); //kiem tra list co trong hay khong
void EnQueue(Queue &s, Node *p); //them 1 node vao dau
int DeQueue(Queue &s);//xoa node dau

//nhap xuat
void Input(Queue &s); //nhap danh sach
void Output(Queue &s); //in danh sach
