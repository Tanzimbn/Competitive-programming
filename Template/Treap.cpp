struct Treap {
    struct Node {
        int x = 0;
        int pr;
        char c;
        int sz = 1;
        Node* left = nullptr;
        Node* right = nullptr;
 
        Node(char c): c(c) {
            pr = rand();
        }
    };
 
    Node* root = nullptr;
 
    Treap() {}
 
    void push_back(char c) {
        root = merge(root, new Node(c));
    }
 
    void push(Node* t) {
        if (t && t->x) {
            t->x = 0;
            swap(t->left, t->right);
            if (t->left) t->left->x ^= 1;
            if (t->right) t->right->x ^= 1;
        }
    }
 
 
    void split(Node* t, Node* &left, Node* &right, int x) {
        if (!t) {
            left = right = nullptr;
            return;
        }
        int left_size = (t->left ? t->left->sz : 0);
        if (x <= left_size) {
            split(t->left, left, t->left, x);
            right = t; update(right);
        }
        else {
            split(t->right, t->right, right, x-left_size-1);
            left = t; update(left);
        }
    }
 
    Node* merge(Node* left, Node* right) {
        if (!left) return right;
        if (!right) return left;
        if (left->pr < right->pr) {
            left->right = merge(left->right, right);
            update(left);
            return left;
        }
        else {
            right->left = merge(left, right->left);
            update(right);
            return right;
        }
    }
 
    int size(Node* &v) { return v ? v->sz : 0; }
 
    void update(Node* &v) { v->sz = 1 + size(v->left) + size(v->right); }
 
    void func(int l, int r) {
        Node* first = nullptr;
        Node* mid = nullptr;
        Node* last = nullptr;
        split(root, first, last, l);
        split(last, mid, last, r - (first ? first->sz : 0) + 1);
        root = merge(merge(first, last), mid);
    }
 
    void ans(Node* t) {
        if (!t) return;
        ans(t->left);
        cout << t->c;
        ans(t->right);
    }
    void help() {
        ans(root);
    }
};
