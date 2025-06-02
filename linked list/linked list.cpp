struct node {
    int data;
    node* next;
};
struct linked_list {
    node* head ;
    node* tail ;
    int len ;
    linked_list() {
        head = tail = nullptr;
        len = 0 ;
    }
    bool empty() {
        return head == nullptr;
    }
    void push_front(int val ) {
        node* curr = new node();
        curr->data = val ;
        if (head == nullptr) {
           head = tail = curr;
        }
        else {
            curr->next = head ;
            head = curr ;
        }
        len++;
    }
    void push_back(int val) {
        node*curr = new node();
        curr->data = val ;
        if (head == nullptr) {
            head = tail = curr;
        }
        else {
            tail->next = curr ;
            curr->next = nullptr ;
            tail = curr ;
        }
        len++;
    }
    void push_at(int val , int idx) {
        if (idx < 0 || idx > len) {
            cout << "out of range" << endl ;
            return;
        }
        node * NewNode = new node();
        NewNode->data = val ;
        if (idx == 0) {
            push_front(val);
        }
        else if (idx == len) {
            push_back(val);
        }
        else {
            node* cur = head;
            for (int i = 1 ; i < idx ; i++) {
                cur = cur->next ;
            }
            NewNode->next = cur->next ;
            cur->next = NewNode ;
        }
        len++;
    }

    void print() {
        node* curr = head ;
        cout << "[ ";
        while (curr != nullptr) {
            cout << curr->data << (curr->next != nullptr ? " , " : " ]") ;
            curr = curr->next ;
        }
        cout << endl ;
    }

    void pop_front() {
        if (len == 0) {
            cout << "Empty list can`t remove" << endl ;
            return;
        }
        else if (len == 1) {
            head = tail = nullptr ;
        }
        else {
            node* curr = head ;
            head = head->next ;
            delete curr ;
        }
        len--;
    }
    void pop_back() {
        if (len == 0) {
            cout << "Empty list can`t remove" << endl ;
            return;
        }
        else if (len == 1) {
            head = tail = nullptr ;
        }
        else {
            node* curr = head->next ;
            node*prev = head ;
            while (curr != tail) {
                prev = curr ;
                curr = curr->next ;
            }
            prev->next = nullptr ;
            tail = prev ;
            delete curr ;
        }
        len--;
    }
    void pop_by_value(int val) {
        if (len == 0) {
            cout << "Empty list can`t remove" << endl ;
            return;
        }
        node* curr = head->next ;
        node*prev = head ;
        if (head->data == val) {
            curr = head ;
            head = head->next ;
            delete curr;
            len--;
            if (len == 0) {
                tail = nullptr;
            }
        }
        else {
            curr = head->next , prev = head;
            while (curr != nullptr) {
                if (curr->data == val){break;}
                prev = curr ;
                curr = curr->next ;
            }
            if (curr == nullptr) {
                cout << "Not found" << endl ;
                return;
            }
            prev->next = curr->next;
            if (tail == curr) {
                tail = prev ;
            }
            delete curr ;
            len--;
        }
    }
};