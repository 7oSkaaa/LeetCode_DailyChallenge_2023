//Author: Walaa AbdElhady
class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		int n = s1.size(), m = s2.size();
		if (m < n)return false;// if the sz of string s2 smaller than s1 ,then it could not contain a substr of s1
		vector<int>frqs1(26, 0), frqs2(26, 0), clear(26, 0);
		// store frq of chars in s1
		for (int i = 0; i < n; i++) frqs1[s1[i] - 'a']++;

		for (int i = 0; i <= m - n; i++) {
			//we count frqs of each substr in s2 which has sz equal to sz of s1
			for (int j = i; j < i + n; j++) {
				frqs2[s2[j] - 'a']++;
			}
			// if this substr has same frq as s1, then s2 has permutation of s1
			if (frqs1 == frqs2)return true;
			frqs2 = clear;// clear frqs2 to count frq of another substr
		}
		// if there are not substr in s2 has same frq as s1
		return false;
	}

};