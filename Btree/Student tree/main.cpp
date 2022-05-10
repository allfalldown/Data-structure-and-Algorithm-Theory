#include <iostream>
#include <math.h>
#include <string>

using namespace std;

struct Student{
	int mssv;
	string ho, ten;
	double dtb;

	void Display(){
		cout << "--------" << endl;
		cout << "Mssv: " << mssv << endl;
		cout << "Ho sinh vien: " << ho << endl;
		cout << "Ten sinh vien: " << ten << endl;
		cout << "Diem trung binh: " << dtb << endl;
	}
};

struct Node{
	Student info;
	struct Node* pLeft;
	struct Node* pRight;
};

typedef Node* Tree;

void Init(Tree& t){t = NULL;}

Node* GetNode(int mssv, string ho, string ten, double dtb){
	Node* p = new Node;
	if (p == NULL)
		return NULL;
	p->info.mssv = mssv;
	p->info.ho = ho;
	p->info.ten = ten;
	p->info.dtb = dtb;
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}

int InsertNode(Tree &t, int mssv, string ho, string ten, double dtb){
	if (t != NULL){
		if (t->info.mssv < mssv)
			InsertNode(t->pRight, mssv, ho, ten, dtb);
		if (t->info.mssv > mssv)
			InsertNode(t->pLeft, mssv, ho, ten, dtb);
		return 0;
	}
	t = GetNode(mssv, ho, ten, dtb);
	if (t == NULL)
		return -1;
	return 1;
}


void Input(Tree &t){
	int n;
	cout << "Nhap so sinh vien: "; cin >> n;
	Init(t);
	for (int i = 0; i < n; i++){
		cout << "Sinh vien thu " << i+1 << endl;
		int mssv; cout << "Nhap mssv: "; cin >> mssv;
		string ho; cout << "Ho sinh vien: "; cin >> ho;
		string ten; cout << "Ten sinh vien: "; cin >> ten;
		double dtb; cout << "Diem trung binh: "; cin >> dtb;
		InsertNode(t, mssv, ho, ten, dtb);
	}
}

void XuatLNR(Tree t){
	if (t == NULL)
		return;
	XuatLNR(t->pLeft);
	t->info.Display();
	XuatLNR(t->pRight);
}

void XuatRNL(Tree t){
	if (t == NULL)
		return;
	XuatRNL(t->pRight);
	t->info.Display();
	XuatRNL(t->pLeft);
}

void XuatNLR(Tree t){
	if (t == NULL)
		return;
	t->info.Display();
	XuatNLR(t->pLeft);
	XuatNLR(t->pRight);
}

int SoSanhDiem(Student x, Student y) { 
    if (x.dtb > y.dtb)
		return 1;
	if (x.dtb == y.dtb)
		return 0;
	return -1;
}

Node* TimDiem(Tree T, double dtb){
    if (T != NULL) {
        if (T->info.dtb < dtb) {
            Node *P = T;
            return P;
        }

        if (T->info.dtb >= dtb) {
            Node *node = TimDiem(T->pLeft, dtb);
            if (node != NULL)
                return node;
            else 
                return TimDiem(T->pRight, dtb); 
        }
    }
    return NULL;
}

int XoaNode(Tree &T, Student x){
    if (T == NULL)
        return 0;
    else if (SoSanhDiem(T->info, x) > 0)
        return XoaNode(T->pLeft, x);
    else if (SoSanhDiem(T->info, x) < 0)
        return XoaNode(T->pRight, x);
    else {
        Node *P = T;
        if (T->pLeft == NULL)
            T = T->pRight;    
        else if (T->pRight == NULL)
            T = T->pLeft;   
        else {
            Node *S = T, *Q = S->pLeft;
            while (Q->pRight != NULL) {
                S = Q;
                Q = Q->pRight;
            }
            P->info = Q->info;
            S->pRight = Q->pLeft;
            delete Q;
        }
    }
    return 1;
}

int main(){
	Tree t;
	Input(t);
	cout << "Hien thi cay nhi phan: (LNR)" << endl;	
	XuatLNR(t);
	cout << endl << "Hien thi cay nhi phan: (NLR)" << endl;
	XuatNLR(t);
	cout << endl << "Hien thi cay nhi phan: (RNL)" << endl;
	XuatRNL(t);

	int del = 1;
    while (del) {
        Node* node = TimDiem(t, 5);
        if (node != NULL) {
            cout << "Del" << endl;
            del = XoaNode(t, node->info);
        } else {
            cout << "Null" << endl;
            del = 0;
        }
    }

	cout << "Sau khi xoa" << endl;
	cout << "Hien thi cay nhi phan: (LNR)" << endl;	
	XuatLNR(t);
	cout << endl << "Hien thi cay nhi phan: (NLR)" << endl;
	XuatNLR(t);
	cout << endl << "Hien thi cay nhi phan: (RNL)" << endl;
	XuatRNL(t);
	return 0;
}
