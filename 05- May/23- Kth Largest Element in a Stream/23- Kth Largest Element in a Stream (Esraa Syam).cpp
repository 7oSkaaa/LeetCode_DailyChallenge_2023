// author: Esraa Syam
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename K, typename V, typename Comp = std::less<K>>
using ordered_map = tree<K, V, Comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename Comp = std::less<K>>
using ordered_set = ordered_map<K, null_type, Comp>;

template <typename K, typename V, typename Comp = std::less_equal<K>>
using ordered_multimap = tree<K, V, Comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename Comp = std::greater_equal<K>>
using ordered_multiset = ordered_multimap<K, null_type, Comp>;
// order_of_key(k) : number of items strictly smaller than k
// find_by_order(k) : k-th largest element (counting from zero)
class KthLargest {
public:
    /**
     * solution idea: 
     * 1- use ordered_multiset to store the numbers
     * 2- insert the numbers in the constructor
     * 3- in add function, insert the number and return the kth largest number by using find_by_order(k) that returns the k-th largest element (counting from zero)
    */
    ordered_multiset < int > ms;
    int kk;
    KthLargest(int k, vector<int>& nums) {
        kk = k;
        for(auto & x : nums) ms.insert(x); // insert the elements in the multiset
    }
    
    int add(int val) {

        ms.insert(val); // insert the new value
        int ans = *ms.find_by_order(kk - 1); // find_by_order(k) : k-th largest element (counting from zero) so we need to subtract 1
        return ans;
    }
};
