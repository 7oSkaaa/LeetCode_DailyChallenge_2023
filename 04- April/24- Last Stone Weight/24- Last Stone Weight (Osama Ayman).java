// Author: Osama Ayman
// Time & Space: O(n)
class Solution {
    public int lastStoneWeight(int[] stones) {
        // sorted descendingly
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for(int x: stones){
            pq.add(x);
        }
        while(pq.size() > 1){
            // get the heaviest two stones
            int y = pq.poll();
            int x = pq.poll();
            if(x!=y){
                pq.add(y-x);
            }
            // if x & y are equal do not add anything to the queue.
        }
        // if empty return 0, otherwise return the element
        return pq.isEmpty() ? 0:pq.poll();
    }
}