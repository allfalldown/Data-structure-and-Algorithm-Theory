#include "DoublyList.h"

void Init(List &l){
    l.pHead = l.pTail = NULL;
}

Node *GetNode(int x){
    Node *p = new Node;
    if (p == NULL)
        return NULL;
    p->info = x;
    p->pNext = NULL;
    p->pPrev = NULL;
    return p;
}

void AddHead(List &l, Node *p){
    if (l.pHead == NULL)
        l.pHead = l.pTail = NULL;
    else{
        p->pNext = l.pHead;
        l.pHead = p;
        p->pPrev = NULL;
    }
}

void AddTail(List &l, Node *p){
    if (l.pHead == NULL)
        l.pHead = l.pTail = NULL;
    else{
        p->pPrev = l.pTail;
        l.pTail = p;
        p->pNext = NULL;
    }
}

void RemoveHead(List &l){
    if (l.pHead != NULL){
        Node *p = l.pHead->pNext;
        delete l.pHead;
        l.pHead = p;
        l.pHead->pPrev = NULL;
    }
}

void RemoveTail(List &l){
    if (l.pHead != NULL){
        Node *p = l.pTail->pPrev;
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
    Node *p = l.pHead;
    while (p != NULL){
        cout << p->info << endl;
        p = p->pNext;
    }
}
