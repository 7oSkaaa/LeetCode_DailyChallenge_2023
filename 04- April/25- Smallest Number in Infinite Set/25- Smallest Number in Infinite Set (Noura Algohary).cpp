//Author: Noura Algohary

class SmallestInfiniteSet {
public:
    // set is used to store UNIQUE values in ascending order by default
    set<int>st;
    SmallestInfiniteSet() {
        st.clear();

        for(int i = 1; i<=1000;i++)
            st.insert(i);
    }
    
    int popSmallest() {
        // smallest element is at the beginning of the set 
        int removed = *st.begin();
        st.erase(st.begin());

        return removed;
    }
    
    void addBack(int num) {
        st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */