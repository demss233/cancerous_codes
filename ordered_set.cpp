#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

using namespace __gnu_pbds;
template <class T> using tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

/*

find_by_order() : returns an iterator to the k-th largest element (counting from zero)

order_of_key() : the number of items in a set that are strictly smaller than our item

to erase : any.erase(any.find_by_order(any.order_of_key(val)));

don't use .find() because it will always return .end()

*/
