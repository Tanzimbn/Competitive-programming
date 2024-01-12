int ar[100005];
struct node{
  node *left, *right;
  int val;
  node(int a = 0, node *b = NULL, node *c = NULL) :
    val(a), left(b), right(c) {} // ** Constructor

  int merge(int x, int y) {
    return x + y;
  }

  void build(int l, int r) {  // We are not  initializing values for now.
    if(l == r) {
        val = ar[l];
        return; // We reached leaf node, No need more links
    }
    left = new node(); // Create new node for Left child
    right = new node();// We are creating nodes only when necessary!
    int mid = l + r >> 1;
    left -> build(l, mid);
    right -> build(mid+1, r);
    val = merge(left -> val, right -> val);
  }


  node *update(int l, int r, int idx, int v) {    
    if(r < idx || l > idx) return this; // Out of range, use this node.
    if(l == r) {  // Leaf Node, create new node and return that.
      node *ret = new node(val, left, right);      
      ret -> val += v;
      return ret;
      // we first cloned our current node, then added v to the value.
    }
    int mid = l + r >> 1;
    node *ret = new node(val); //Create a new node, as idx in in [l, r]  
    ret -> left = left -> update(l, mid, idx, v);
    ret -> right = right -> update(mid+1, r, idx, v);
    // Note that 'ret -> left' is new node's left child,
    // But 'left' is current old node's left child.
    // So we call to update idx in left child of old node.
    // And use it's return node as new node's left child. Same for right.
    ret -> val = merge( ret -> left -> val, ret -> right -> val); // Update value.
    return ret; // Return the new node to parent.
  }

  // [l, r] node range, [i, j] query range.
  int query(int l, int r, int i, int j) {
    if(r < i || l > j) return 0; // out of range
    if(i <= l && r <= j) { // completely inside
      return val;  // return value stored in this node
    } int mid = l + r >> 1;
    return merge(left -> query(l, mid, i, j), right -> query(mid+1, r, i, j));
  }

}*root[100005]; 
int main() {
  root[0] = new node();
  root[0] -> build(0, n - 1);
}
