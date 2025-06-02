struct node {
    int item ;
    node* next ;
};

struct Stack {
    node* head ;

    Stack() { head = NULL; }
    ~Stack() {
        while (!empty()) {
            pop();
        }
    }

    bool empty(){return head == NULL;}

    void push(int val ) {
        node * cur = new node() ;
        cur->item = val ;
        cur->next = head ;
        head = cur ;
    }
    void pop() {
        if (empty()) {
            throw underflow_error("Stack underflow: cannot pop from an empty stack.");
        }
        node*temp = head ;
        head = head->next ;
        delete temp ;
    }

    void display() {
        if (empty()) {
            cout << "[ ]\n";
            return;
        }
        node *cur = head ;
        cout << "[ ";
        while (cur != nullptr) {
            cout << cur->item << (cur->next != nullptr ? " , " : " ]") ;
            cur = cur->next;
        }
        cout << endl ;
    }

    int top() {
        if (empty()) {
            throw underflow_error("Stack is empty: no top element.");
            return 0 ;
        }
        return head->item ;
    }

};
