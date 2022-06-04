#include <iostream>
#include <fstream> 
#include <cmath> 
#include <vector>
#include <algorithm>

using namespace std;

struct Node{
    int data;
    Node *pLeft;
    Node *pRight;
};

typedef Node* Tree;

Node* GetNode(int data){
    Node *p = new Node;
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

void NLR(Tree head, vector<int> &vec){
    if (head){
        cout << head->data << " ";
        vec.push_back(head->data);
        NLR(head->pLeft, vec);
        NLR(head->pRight, vec); 
    }
}

void ReadData(int &n, Tree &mytree){ //read file data.txt
    ifstream file;
    file.open("data.txt");
    string data;
    file >> data; n = stoi(data);
    cout << n << endl;
    for (int i=0; i<n; i++){
        file >> data;
        Node *p = GetNode(stoi(data));
        AddNode(mytree, p);
    }
    file.close();
}

void ReadInput(int &x, int &y, int &z, int &t){ //read file input.txt
    ifstream ifile;
    ifile.open("input.txt");
    string data;
    ifile >> data; x = stoi(data);
    ifile >> data; y = stoi(data);
    ifile >> data; z = stoi(data);
    ifile >> data; t = stoi(data);
    ifile.close();
}

int CountNode(Tree head){
    if (head == NULL)
        return 0;
    return (1 + CountNode(head->pLeft) + CountNode(head->pRight));
}

int CountNodeXY(Tree head, int x, int y){
    if (head == NULL)
        return 0;
    if (head->data > x && head->data < y)
        return (1 + CountNodeXY(head->pLeft, x, y) + CountNodeXY(head->pRight, x, y));
    return (CountNodeXY(head->pLeft, x, y) + CountNodeXY(head->pRight, x, y));
}

bool IsPrime(int n){
    if (n < 2) return false;
    for (int i=2; i<sqrt(n); i++){
        if (n % i == 0)
            return false;
    }
    return true;
}

int Left(Tree head){
    if (head->pLeft == NULL)
        return head->data;
    return Left(head->pLeft); 
}

void MinPrime(Tree head, int &min){
    if (head){
        if (IsPrime(head->data) && head->data < min)
            min = head->data;
        MinPrime(head->pLeft, min);
        MinPrime(head->pRight, min);
    }
}

int FindNode(Tree head, int z){ 
    if (head == NULL)
        return 0;
    else{
        if (z < head->data)
            FindNode(head->pLeft, z);
        else if (z > head->data)
            FindNode(head->pRight, z);
        return 1;    
    }
}

void WriteOutput(vector<int> vec, int ex2, int ex3, int ex4, int ex5){
    ofstream out;
    out.open("output.txt");
    sort(vec.begin(), vec.end());
    for (int i=0; i<vec.size(); i++)
        out << vec[i] << " ";
    out << endl << ex2 << endl << ex3 << endl << ex4 << endl << ex5 << endl; 
    out.close();
}

int main(){
    vector<int> vec;

    Tree mytree; Init(mytree);
    int n, x, y, z, t, min = 1000000;

    ReadData(n, mytree);
    ReadInput(x, y, z, t);
    NLR(mytree, vec); cout << endl;

    cout << "Total nodes: " << CountNode(mytree) << endl;
    cout << "Numbers of nodes being greater than " << x << " and less than " << y << ": " << CountNodeXY(mytree, x, y) << endl;
    cout << "The most left node in tree: " << Left(mytree) << endl;
    MinPrime(mytree, min);
    cout << "Min prime in tree: " << min << endl;
    cout << z << " is in tree: " << FindNode(mytree, z) << endl;

    WriteOutput(vec, CountNodeXY(mytree, x, y), Left(mytree), min, FindNode(mytree, z));

    cout << endl;
    return 0;
}