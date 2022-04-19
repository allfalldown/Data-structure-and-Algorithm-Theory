#include "Queue.cpp"

int main(){
    Queue q;
    Input(q);
    while (!IsEmpty(q))
        cout << DeQueue(q) << endl;
    return 0;
}