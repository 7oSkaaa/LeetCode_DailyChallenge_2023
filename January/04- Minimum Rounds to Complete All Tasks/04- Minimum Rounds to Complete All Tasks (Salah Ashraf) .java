// Author: Salah Ashraf

class Solution {
    private int getRounds(int occurrence) {
       if (occurrence == 1) return -1; //it is not possible to complete all tasks
       return (occurrence + 2 ) / 3;
    }
    public int minimumRounds(int[] tasks) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        //store the frequencey of each level of tasks in the HashMap
        for (int task : tasks) {
            if (mp.containsKey(task))
                mp.put(task, mp.get(task) + 1);
            else mp.put(task, 1);
        }
        
        int ans = 0, rounds;
        
        for (int key : mp.keySet()) {
            rounds = getRounds(mp.get(key));
            if (rounds == -1)
                return -1; //it is not possible to complete all tasks
            
            //increment the ans with rounds of each level
            ans += rounds;
        }
        return ans; // return the answer 
    }
}
