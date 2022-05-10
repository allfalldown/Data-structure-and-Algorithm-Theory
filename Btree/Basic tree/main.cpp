#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

struct Node{
	int info;
	struct Node* pLeft;
	struct Node* pRight;
};

typedef Node* Tree;

void Init(Tree& t){t = NULL;}

Node* GetNode(int x){
	Node* p = new Node;
	if (p == NULL)
		return NULL;
	p->info = x;
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}

int InsertNode(Tree &t, int x){
	if (t != NULL){
		if (t->info < x)
			InsertNode(t->pRight, x);
		if (t->info > x)
			InsertNode(t->pLeft, x);
		return 0;
	}
	t = GetNode(x);
	if (t == NULL)
		return -1;
	return 1;
}

void Input(Tree &t){
	int n;
	cout << "Nhap n: "; cin >> n;
	Init(t);
	for (int i = 0; i < n; i++){
		int x; cout << "Nhap x = "; cin >> x;
		InsertNode(t, x);
	}
}

void Input_txt(Tree& t, const char* path){
	ifstream ifs;
	ifs.open(path);
	int n; ifs >> n;
	Init(t);
	for (int i = 0; i < n; i++)
	{
		int x;
		ifs >> x;
		InsertNode(t, x);
	}
	ifs.close();
}

void XuatLNR(Tree t){
	if (t == NULL)
		return;
	XuatLNR(t->pLeft);
	cout << t->info << " ";
	XuatLNR(t->pRight);
}

void XuatRNL(Tree t){
	if (t == NULL)
		return;
	XuatRNL(t->pRight);
	cout << t->info << " ";
	XuatRNL(t->pLeft);
}

void XuatNLR(Tree t){
	if (t == NULL)
		return;
	cout << t->info << " ";
	XuatNLR(t->pLeft);
	XuatNLR(t->pRight);
}

void XuatNRL(Tree t){
	if (t == NULL)
		return;
	cout << t->info << " ";
	XuatNRL(t->pRight);
	XuatNRL(t->pLeft);
}

void XuatLRN(Tree t){
	if (t == NULL)
		return;
	XuatLRN(t->pLeft);
	XuatLRN(t->pRight);
	cout << t->info << " ";	
}

void XuatRLN(Tree t){
	if (t == NULL)
		return;
	XuatRLN(t->pRight);
	XuatRLN(t->pLeft);
	cout << t->info << " ";
}

Node* findX(Tree t, int x){
	if (t == NULL)
		return NULL;
	if (t->info == x)
		return t;
	if (x < t->info)
		return findX(t->pLeft, x);
	return findX(t->pRight, x);
}

int DemNode(Tree t){
	if (t == NULL)
		return 0;
	int a = DemNode(t->pLeft);
	int b = DemNode(t->pRight);
	return (a + b + 1);
}

int DemNodeLa(Tree t){
	if (t == NULL)
		return 0;
	int a = DemNodeLa(t->pLeft);
	int b = DemNodeLa(t->pRight);
	if (t->pLeft == NULL && t->pRight == NULL)
		return (a + b + 1);
	return a + b;
}

int ChieuCao(Tree t){
	if (t == NULL)
		return 0;
	int a = ChieuCao(t->pLeft);
	int b = ChieuCao(t->pRight);
	if (a > b)
		return a + 1;
	else
		return b + 1;
}

int Ktcp(int n) {
	int sqr = sqrt(n);
	return (sqr * sqr == n);
}

int DemCp(Tree t){
	if (t == NULL)
		return 0;
	int a = DemCp(t->pLeft);
	int b = DemCp(t->pRight);
	if (Ktcp(t->info) == 1)
		return a + b + 1;
	return a + b;
}

int findMin(Tree t){
	if (t->pLeft == NULL)
		return (t->info);
	return findMin(t->pLeft);
}

int findMax(Tree t){
	if (t->pRight == NULL)
		return (t->info);
	return findMax(t->pRight);
}

int TongNode(Tree t){
	if (t == NULL)
		return 0;
	int a = TongNode(t->pLeft);
	int b = TongNode(t->pRight);
	return(a + b + t->info);
}

float TBCNode(Tree t){
	int s = TongNode(t);
	int dem = DemNode(t);
	if (dem == 0)
		return 0;
	return (float)s / dem;
}

int main(){
	Tree t;
	cout << "Nhap cay nhi phan tu ban phim: " << endl;
	Input(t);
	cout << "Hien thi cay nhi phan: (LNR)" << endl;
	XuatLNR(t);
	cout << endl << "Hien thi cay nhi phan: (LRN)" << endl;
	XuatLRN(t);
	cout << endl << "Hien thi cay nhi phan: (NLR)" << endl;
	XuatNLR(t);
	cout << endl << "Hien thi cay nhi phan: (NRL)" << endl;
	XuatNRL(t);
	cout << endl << "Hien thi cay nhi phan: (RLN)" << endl;
	XuatRLN(t);
	cout << endl << "Hien thi cay nhi phan: (RNL)" << endl;
	XuatRNL(t);

	cout << endl << "Nhap cay nhi phan tu file: ";
	Input_txt(t, "input.txt");
	cout << endl << "Hien thi cay nhi phan: (LNR)" << endl;
	XuatLNR(t);
	cout << endl << "Hien thi cay nhi phan: (LRN)" << endl;
	XuatLRN(t);
	cout << endl << "Hien thi cay nhi phan: (NLR)" << endl;
	XuatNLR(t);
	cout << endl << "Hien thi cay nhi phan: (NRL)" << endl;
	XuatNRL(t);
	cout << endl << "Hien thi cay nhi phan: (RLN)" << endl;
	XuatRLN(t);
	cout << endl << "Hien thi cay nhi phan: (RNL)" << endl;
	XuatRNL(t);

	int temp; cout << endl << "Nhap so x can tim: "; cin >> temp;
	if (findX(t, temp))
		cout << endl << "Tim thay x." << endl;
	else
		cout << "Khong tim thay." << endl;
	cout << "So nut: " << DemNode(t);
	cout << endl << "So nut la: " << DemNodeLa(t);
	cout << endl << "Dem so chinh phuong: " << DemCp(t);
	cout << endl << "Min: " << findMin(t);
	cout << endl << "Max: " << findMax(t);
	cout << endl << "Trung binh cong: " << TBCNode(t);
}
