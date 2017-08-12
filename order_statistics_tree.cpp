#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// The functions are the same as set's, with two new features: find_by_order() and order_of_key()

// Example: X = [1,2,4,8,16] (ordered_set)

// cout<<*X.find_by_order(1)<<endl; // 2
// cout<<*X.find_by_order(2)<<endl; // 4
// cout<<*X.find_by_order(4)<<endl; // 16
// cout<<(end(X)==X.find_by_order(6))<<endl; // true

// cout<<X.order_of_key(-5)<<endl;  // 0
// cout<<X.order_of_key(1)<<endl;   // 0
// cout<<X.order_of_key(3)<<endl;   // 2
// cout<<X.order_of_key(4)<<endl;   // 2
// cout<<X.order_of_key(400)<<endl; // 5

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;


// For multiset, use a set of pair {elem, id (e.g., time of insertion)}
// ordered_multiset me;
// t = 0
// me.insert({x, t++});
// me.erase(me.lower_bound({x, 0}));
// cout << me.order_of_key({x, 0}) << "\n";
typedef tree<
pair<int,int>,
null_type,
less<pair<int, int> >,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_multiset;