// Author: Osama Ayman
// Time: O((m+n) log(n))
// Space: O(n)
class SmallestInfiniteSet {
    // use a priority queue to keep track of the added integers in increasing order
    // we will only add numbers that are less than the current number
    PriorityQueue<Integer> addedIntegers;
    // set to tell if a number is already in the pq, so we don't add it again to the pq
    Set<Integer> set;
    // represents the lowest number in the infinte set
    int cur;
    public SmallestInfiniteSet() {
        addedIntegers = new PriorityQueue<>();
        set = new HashSet<>();
        // initially set to 1
        cur = 1;
    }
    
    public int popSmallest() {
        // if pq is empty then the lowest number is the cur
        if(addedIntegers.isEmpty()){
            // return it, then increment it by 1
            return cur++;
        }
        // else if pq not empty, then the top number in it is lower than the cur
        int pop = addedIntegers.poll();
        // remove it from set as we removed it from pq
        set.remove(pop);
        return pop;
    }
    
    public void addBack(int num) {
        // if the pq already contains the num or the num is greater than or equal to
        // cur, dont add it
        if(set.contains(num) || cur <= num) return;
        // else add it
        set.add(num);
        addedIntegers.add(num);
    }
}

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet obj = new SmallestInfiniteSet();
 * int param_1 = obj.popSmallest();
 * obj.addBack(num);
 */