#include "Stack.cpp"

int main(){
    Stack s;
    Input(s);
    cout << "== Result Here ==" << endl;
    while (!IsEmpty(s))
        cout << Pop(s) << endl;
    return 0;
}