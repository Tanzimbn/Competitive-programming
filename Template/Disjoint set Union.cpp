void init(int N) {
    for (int i = 0; i < N; ++i) {
        pre[i] = i;
        height[i] = 0;
    }
}

int find(int node) {
    if (pre[node] != node) {
        pre[node] = find(pre[node]);
    }
    return pre[node];
}

void unite(int A, int B) {
    int A = find(A);
    int B = find(B);
    if(A==B) return;
    if (height[A] > height[B]) {
        pre[B] = A;
        height[A] = max(height[A], height[B] + 1);
    } else {
        pre[A] = B;
        height[B] = max(height[B], height[A] + 1);
    }
}
