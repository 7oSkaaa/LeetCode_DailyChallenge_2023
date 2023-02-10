// Author: Osama Ayman
class Solution {
    public long distinctNames(String[] ideas) {
        HashSet<String> ideaSet = new HashSet<>();
        HashSet<Character> possibleFirstChars = new HashSet<>();
        // get all possible chars that can be replaced with
        for(String s: ideas){
            possibleFirstChars.add(s.charAt(0));
            ideaSet.add(s);
        }
        HashMap<Character, HashMap<Character, Integer>> hm = new HashMap<>();
        for(String orgString: ideas){
            // try all strings with first char replaced
            for(char newChar: possibleFirstChars){
                char orgChar = orgString.charAt(0);
                if(orgChar==newChar) continue;
                String newString = newChar + orgString.substring(1, orgString.length());
                // if new String is in ideas, it cant be used as a name
                if(ideaSet.contains(newString)) continue;
                // states that this original string can be replaced with new char
                if(hm.containsKey(newChar)){
                    HashMap<Character, Integer> map = hm.get(newChar);
                    map.put(orgChar, map.getOrDefault(orgChar,0)+1 );
                }
                else {
                    HashMap<Character, Integer> map = new HashMap<>();
                    map.put(orgChar, 1);
                    hm.put(newChar, map);
                }

            }
        }
        long total = 0;
        // for each char get the corresponding replacement count
        for(char Pkey: hm.keySet()){
            HashMap<Character, Integer> Smap = hm.get(Pkey);
            for(char Skey: Smap.keySet()){
                int cur = Smap.get(Skey);
                if(!hm.containsKey(Skey) || !hm.get(Skey).containsKey(Pkey)) continue;
                int curPair = hm.get(Skey).get(Pkey);
                total += cur*curPair;
            }
        }
        return total;


    }
}