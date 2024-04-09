#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef
tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistordered_set1;
typedef
tree<int,null_type,greater<int>,rb_tree_tag,
tree_order_statordered_set2;
typedef tree<pair<long long,long
long>,null_type,less<pair<long long,long
long>>,rb_tree_tag,
tree_order_statistics_node_update> ordered_set;
// order_of_key(x) returns number of elements strictly less than x
// find_by_order(x) return x th element of the set (0 based index)
