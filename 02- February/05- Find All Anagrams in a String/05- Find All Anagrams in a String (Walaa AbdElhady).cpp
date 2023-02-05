//Author: Walaa AbdElhady
class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		int n = s.size(), m = p.size(), stIdx = 0;
		vector<int>ans;//to store start idxs of all anagrams of string
		if (n < m)return {};// if the sz of string s smaller than p ,then there are no  Anagrams in a String 
		vector<int>frqS(26, 0), frqP(26, 0), clear(26, 0);
		// store frq of chars in p to search if there is an anagram like it or not
		for (int i = 0; i < m; i++)frqP[p[i] - 'a']++;
		for (int i = 0; i <= n - m; i++) {
			stIdx = i;// to store start idx if there is an anagram
			//loop to count frqs of each substr in s which has sz equal to sz of p
			for (int j = i; j < i + m; j++) {
				frqS[s[j] - 'a']++;
			}
			// if this substr has same frq as p, then it is an anagram and then push first idx
			if (frqS == frqP)ans.push_back(stIdx);
			frqS = clear;// clear frqs2 to count frq of another substr (anagram)
		}
		return ans;
	}
};
