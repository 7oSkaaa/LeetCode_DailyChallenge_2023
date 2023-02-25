// Author: Osama Ayman
class Solution {
    
    class Pair{
        int c;
        int p;
        public Pair(int c, int p){
        this.c=c;
        this.p=p;
        }
        
    }
    public int findMaximizedCapital(int k, int w, int[] profits, int[] capital) {
        int cap = w;
        int cnt = 0;
        // min heap to get the least capital elements first
        PriorityQueue<Pair> pq = new PriorityQueue<>((a,b) -> a.c - b.c);
        for(int i=0; i<capital.length; i++){
            pq.add(new Pair(capital[i], profits[i]));
        }
        // max heap to get the max profit first
        PriorityQueue<Integer> avail = new PriorityQueue<>(Collections.reverseOrder());
        while(k-->0){
            // if current capital is greater than or equal the cur least capital, then 
            // we can take its proft, so add it to the available queue
        while(!pq.isEmpty() && pq.peek().c <= cap){
            avail.add(pq.poll().p);
        }
        // if there is no available items, we cant increase our profit further.
        if(avail.isEmpty()) return cap;
        // get the max available profit.
        cap += avail.poll();
        }

        return cap;
        
    }

}