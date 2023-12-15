// Here, split based on index , may change according to problem
// 
using treap_val = char; // treap value data type
struct node {
    node *L, *R;
    int W, S;
    treap_val V;
    bool F;
    node(char x) {
        L = R = 0;
        W = rand();
        S = 1;
        V = x;
        F = 0;
    }
};

int size(node *treap) {
    return (treap == 0 ? 0 : treap->S);
}

void push(node *treap) {
    if (treap && treap->F) {
        treap->F = 0;
        swap(treap->L, treap->R);
        if (treap->L) treap->L->F ^= 1;
        if (treap->R) treap->R->F ^= 1;
    }
}
// k -> 1-indexed || K index in left tree
void split(node *treap, node *&left, node *&right, int k) {
    if (treap == 0)
        left = right = 0;
    else {
        push(treap);
        if (size(treap->L) < k) {
            split(treap->R, treap->R, right, k - size(treap->L) - 1);
            left = treap;
        }
        else {
            split(treap->L, left, treap->L, k);
            right = treap;
        }
        treap->S = size(treap->L) + size(treap->R) + 1;
    }
}
// root - left root - right root -> merge tree root is treap
void merge(node *&treap, node *left, node *right) {
    if (left == 0) treap = right;
    else if (right == 0) treap = left;
    else {
        push(left);
        push(right);
        if (left->W < right->W) {
            merge(left->R, left->R, right);
            treap = left;
        }
        else {
            merge(right->L, left, right->L);
            treap = right;
        }
        treap->S = size(treap->L) + size(treap->R) + 1;
    }
}
void add(node *&treap, treap_val x) {
    merge(treap, treap, new node(x));
}
// insert at position upper_bound(x)
void insert(node *&treap, int x) {
    if(treap == 0) {
        treap = new node(x); return;
    }
    node *a, *b;
    split(treap, a, b, x);
    add(a, x);
    merge(treap, a, b);
}
// pos -> 1-indexed 
void remove(node *&treap, int pos) {
    node *A, *B, *C;
    split(treap, A, B, pos - 1);
    split(B, B, C, 1);
    merge(treap, A, C);
}
void reverse(node *&treap, int x, int y) {
    node *A, *B, *C;
    split(treap, A, B, x - 1);
    split(B, B, C, y - x + 1);
    B->F ^= 1;
    merge(treap, A, B);
    merge(treap, treap, C);
}
void print(node *treap) {
    if (treap == NULL) return;
    push(treap);
    print(treap->L);
    cout << treap->V;
    print(treap->R);
}
