class Solution {
    private int getRounds(int occurrence) {
       if (occurrence == 1) return -1;
       return (occurrence + 2 ) / 3;
    }
    public int minimumRounds(int[] tasks) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        for (int task : tasks) {
            if (mp.containsKey(task))
                mp.put(task, mp.get(task) + 1);
            else mp.put(task, 1);
        }
        int ans = 0, rounds;
        for (int key : mp.keySet()) {
            rounds = getRounds(mp.get(key));
            if (rounds == -1)
                return -1;
            ans += rounds;
        }
        return ans;
    }
}
