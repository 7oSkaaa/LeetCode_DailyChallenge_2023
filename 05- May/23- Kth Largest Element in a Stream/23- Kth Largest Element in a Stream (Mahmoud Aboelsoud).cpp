// Author: Mahmoud Aboelsoud

// the needed includes for using the multi ordered set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// define the multi ordered set with greater equal comparator to store duplicates in descending order
#define multi_ordered_set tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

// the idea is to use a multi ordered set to store the elements in descending order
// and find the k'th largest element using find_by_order function


class KthLargest {
public:
    // k: the k'th largest element
    int k;
    // ms: the multi ordered set
    multi_ordered_set ms;

    // constructor
    KthLargest(int k, vector<int>& nums) {
        // initialize k and insert all elements in the multi ordered set
        this -> k = k;
        for(auto&i: nums) ms.insert(i);
    }
    
    // add a new element to the multi ordered set and return the k'th largest element
    int add(int val) {
        // insert the new element
        ms.insert(val);

        // return the k'th largest element
        return *ms.find_by_order(k - 1);
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
