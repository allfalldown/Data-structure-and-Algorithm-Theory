#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *pLeft;
    Node *pRight;
};

typedef Node* Tree;

Node* GetNode(int data){
    Node* p = new Node;
    p->data = data;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

void Init(Tree &head){
    head = NULL;
}

void DestroyTree(Tree &head){
    if (head){
        DestroyTree(head->pLeft);
        DestroyTree(head->pRight);
        delete head;
    }
}

void AddNode(Tree &head, Node *node){
    if (head){
        if (node->data < head->data)
            AddNode(head->pLeft, node);
        else
            AddNode(head->pRight, node);
    }
    else
        head = node;
}

void NLR(Tree head){
    if (head){
        cout << head->data << " ";
        NLR(head->pLeft);
        NLR(head->pRight); 
    }
}

bool IsLeafNode(Tree btree){
	return (btree->pLeft == NULL && btree->pRight == NULL);
}

void PrintLeafNode(Tree btree, vector<int> &vec){
	if (btree){
	    if (IsLeafNode(btree)) {
            cout << btree->data << " ";
            vec.push_back(btree->data);
        }
	    PrintLeafNode(btree->pLeft, vec);
        PrintLeafNode(btree->pRight, vec);
    }
}

bool IsSquareNumber(int n){
    int i = 0;
    while(i*i <= n){
        if(i*i == n)
            return true;
        i++;
    }
    return false;
}

Node* SearchStandFor(Tree &p, Tree &q){
    if (p->pLeft)
        return SearchStandFor(p->pLeft, q);
    Node* temp = p;
    q->data = p->data;
    p = p->pRight;
    return temp;
}

void PrintSquareNumber(Tree head, vector<int> &vec){
    if (head){
        if (IsSquareNumber(head->data)){
            cout << head->data << " ";
            vec.push_back(head->data);
        }
        PrintSquareNumber(head->pLeft, vec);
        PrintSquareNumber(head->pRight, vec);
    }
}

void DeleteNode(Tree &btree){
    Node* temp = btree;
    if (!btree->pLeft && !btree->pRight)
        btree = NULL;
    else if (btree->pLeft && !btree->pRight)
        btree = btree->pLeft;
    else if (!btree->pLeft && btree->pRight)
        btree = btree->pRight;
    else
        temp = SearchStandFor(btree->pLeft, btree);
    delete temp;
}

void DeleteSquareNumber(Tree& t){
    if (!t)
        return;
    DeleteSquareNumber(t->pLeft);
    DeleteSquareNumber(t->pRight);
    if (IsSquareNumber(t->data))
        DeleteNode(t);
}

void PrintNLR(Tree head, vector<int> &vec){
    if (head){
        cout << head->data << " ";
        vec.push_back(head->data);
        PrintNLR(head->pLeft, vec);
        PrintNLR(head->pRight, vec);
    }
}

void ReadFile(string filename, int &n, Tree &btree){
    ifstream is(filename);
    string tmp;
    is >> tmp;
    n = stoi(tmp);
    for (int i=0; i<n; i++){
        is >> tmp;
        Node* p = GetNode(stoi(tmp));
        AddNode(btree, p);
    }
    is.close();
}

void PrintFile(string filename, vector<int> vec1, vector<int> vec2, vector<int> vec3){
    ofstream os(filename);
    for (int i=0; i<vec1.size(); i++){
        os << vec1[i] << " ";
    }
    os << endl;
    for (int i=0; i<vec2.size(); i++){
        os << vec2[i] << " ";
    }
    os << endl;
    for (int i=0; i<vec3.size(); i++){
        os << vec3[i] << " ";
    }
    os << endl;
    os.close();
}

int main(){
    int n;
    vector<int> vec1, vec2, vec3;
    Tree btree;
    Init(btree);
    ReadFile("data.txt", n, btree);
    cout << endl;
    PrintLeafNode(btree, vec1);
    cout << endl;
    PrintSquareNumber(btree, vec2);
    DeleteSquareNumber(btree);
    cout << endl;
    PrintNLR(btree, vec3);
    cout << endl;
    PrintFile("output.txt", vec1, vec2, vec3);
    return 0;
}