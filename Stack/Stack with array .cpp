int const N = 100;
struct Stack{
    int idx ;
    int item[N];

    Stack() { idx = -1; }
    bool empty(){return idx == -1;}

    void push(int val) {
        if (idx == N) {
            cout << "stack overflow" << endl;
            return;
        }
        item[++idx] = val;
    }
    void pop() {
        if (empty()) {
            cout << "stack is empty" << endl ;
        }
        idx--;
    }
    int top() {
        if (empty()) {
            cout << "stack is empty" << endl ;
        }
        return item[idx];
    }
    void print() {
        cout << "[ " ;
        for (int i = idx ; i >=0; i--) {
            cout << item[i] << (i == 0 ? " ]" : " , ");
        }
        cout << endl ;
    }
};