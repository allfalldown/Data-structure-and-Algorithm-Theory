#include "SinglyList.h"

void Init(List &l){
    l.pHead = l.pTail = NULL;
}

Node *GetNode(int x){ 
    Node* p = new Node; //khoi tao 1 node
    if (p == NULL) //kiem tra node co rong khong
        return NULL;
    p->info = x; //truyen du lieu vao node
    p->pNext = NULL;
    return p; 
}

bool IsEmpty(List l){
    if (l.pHead == NULL) // node dau la rong thi la list rong
        return true;
    return false;
}

void AddHead(List &l, Node *p){ //tham khao hinh: https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2013/03/Linkedlist_insert_at_start.png
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else{
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void AddTail(List &l, Node *p){
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else{
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void RemoveHead(List &l){
    if (l.pHead != NULL){
        Node *p = l.pHead->pNext;
        delete l.pHead;
        l.pHead = p;
    }
}

void RemoveTail(List &l){
    if (l.pHead != NULL){
        Node *p = l.pHead;
        while (p->pNext->pNext != NULL){
            p = p->pNext;
        }
        delete l.pTail;
        l.pTail = p;
        l.pTail->pNext = NULL;
    }
}


void Input(List &l){
    Init(l);
    cout << "Number: ";
    int n, x; cin >> n;
    for (int i=0; i<n; i++){
        cout << "Value: "; cin >> x;
        Node *p = GetNode(x);
        AddTail(l, p);
    }
}

void Output(List &l){
    cout << "== Result here ==" << endl;
    Node *p = l.pHead; //gan 1 node bang node dau roi chay tuan tu
    while (p != NULL){
        cout << p->info << endl;
        p = p->pNext; //nhay sang node tiep theo
    }
}

void Swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

void Sort(List &l){
    cout << "== After sort ==" << endl;
    for (Node *p = l.pHead; p != NULL; p=p->pNext){
        for (Node *q = p->pNext; q != NULL; q=q->pNext){
            if (p->info > q->info) //dieu kien xet thu tu
                Swap(p->info,q->info);
        }
    }
    Output(l);
}