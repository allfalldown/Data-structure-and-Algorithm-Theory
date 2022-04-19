#include "Stack.h"

void Init(Stack &s){
    s.pHead = NULL;
}

Node *GetNode(int x){ 
    Node* p = new Node; //khoi tao 1 node
    if (p == NULL) //kiem tra node co rong khong
        return NULL;
    p->info = x; //truyen du lieu vao node
    p->pNext = NULL;
    return p; 
}

bool IsEmpty(Stack l){
    if (l.pHead == NULL) // node dau la rong thi la list rong
        return true;
    return false;
}

void Push(Stack &l, Node *p){ 
    if (l.pHead == NULL)
        l.pHead = p;
    else{
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

int Pop(Stack &l){
    if (l.pHead != NULL){
        int tmp = l.pHead->info;
        Node *p = l.pHead->pNext;
        delete l.pHead;
        l.pHead = p;
        return tmp;
    }
    return -1;
}

void Input(Stack &s){
    Init(s);
    cout << "Number: ";
    int n, x; cin >> n;
    for (int i=0; i<n; i++){
        cout << "Value: "; cin >> x;
        Node *p = GetNode(x);
        Push(s, p);
    }
}