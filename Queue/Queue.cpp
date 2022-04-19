#include "Queue.h"

void Init(Queue &q){
    q.pHead = q.pTail = NULL;
}

Node *GetNode(int x){ 
    Node* p = new Node; //khoi tao 1 node
    if (p == NULL) //kiem tra node co rong khong
        return NULL;
    p->info = x; //truyen du lieu vao node
    p->pNext = NULL;
    return p; 
}

bool IsEmpty(Queue q){
    if (q.pHead == NULL) // node dau la rong thi la list rong
        return true;
    return false;
}

void EnQueue(Queue &q, Node *p){ 
    if (q.pHead == NULL)
        q.pHead = q.pTail = p;
    else{
        q.pTail->pNext = p;
        q.pTail = p;
    }
}

int DeQueue(Queue &q){
    if (q.pHead != NULL){
        int tmp = q.pHead->info;
        Node *p = q.pHead->pNext;
        delete q.pHead;
        q.pHead = p;
        return tmp;
    }
    return -1;
}

void Input(Queue &q){
    Init(q);
    cout << "Number: ";
    int n, x; cin >> n;
    for (int i=0; i<n; i++){
        cout << "Value: "; cin >> x;
        Node *p = GetNode(x);
        EnQueue(q, p);
    }
}