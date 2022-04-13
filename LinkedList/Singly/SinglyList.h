#pragma once
#include <iostream>
using namespace std;
//singly linked list: thiet lap tao ra lien ket cac node, trong do 1 node se bao gom:
// - thong tin cua node
// - con tro toi node tiep theo
// va linkedlist can chua node dau va node cuoi
// mo hinh tai: https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2013/03/Linkedlist.png

// thanh phan cua 1 node, neu info can nhieu thong tin thi luu trong 1 struct khac
struct Node{ 
    int info;
    Node *pNext;
};

// thanh phan cua node chua nhieu gia tri
struct Sample{
    int value1, value2;
};

struct ExNode{
    Sample info;
    ExNode *pNext;
};

//thanh phan cua list
struct List{
    Node *pHead;
    Node *pTail;
};

//thao tac mac dinh
void Init(List &l); //khoi tao danh sach
Node *GetNode(int x); //vi du su dung node luu 1 gia tri duy nhat, luu y dau *, Node co kieu tra ve la pointer
bool IsEmpty(List l); //kiem tra list co trong hay khong
void AddHead(List &l, Node *p); //them 1 node vao dau
//y tuong: node moi dua len dau se tro next vao node dau roi bien node vua them thanh node dau
void AddTail(List &l, Node *p);

//nhap xuat
void Input(List &l); //nhap danh sach
void Output(List &l); //in danh sach

//sap xep node theo yeu cau
void Swap(int &x, int &y); //doi cho 2 gia tri
void Sort(List &l); // vi du sap xep theo be toi lon