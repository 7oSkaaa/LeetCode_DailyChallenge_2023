// author : Omar Sanad

/* 
Here In this solution I will use a data structure call ordered multiset
for more information about this data structre check out this https://www.geeksforgeeks.org/ordered-set-gnu-c-pbds/
briefly the ordered set is like the ordinary set, but we have two extra functions
a function that finds the position of an element,
a function that finds the i_th element
 */

// We have to include some header files for this data structure
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <typename K, typename V, typename Comp = std::less<K>> using 
__ordered_map = tree<K, V, Comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename Comp = std::less<K>> using 
ordered_set = __ordered_map<K, null_type, Comp>;
template <typename K, typename V, typename Comp = std::less_equal<K>> using 
__ordered_multimap = tree<K, V, Comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename Comp = std::less_equal<K>> using 
ordered_multiset = __ordered_multimap<K, null_type, Comp>;

class KthLargest {
public:
    // declare the k in the class itself
    int k;

    // declare an ordered multi set that sorts the elements in descending order (from great to little)
    ordered_multiset < int, greater_equal<int> > ost;
    KthLargest(int k, vector<int>& nums) {
        // assign the given k to the k declared in the class
        this->k = k;

        // add the given elements to the ordered multi set
        for (auto &I : nums)
            ost.insert(I);
    }
    
    int add(int val) {

        // add the given element to the ordered multi set
        ost.insert(val);

        // return the element at the index k
        return *ost.find_by_order(k - 1);
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
