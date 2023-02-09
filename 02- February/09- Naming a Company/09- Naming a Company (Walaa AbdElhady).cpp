class Solution {
public:
	long long distinctNames(vector<string>& ideas) {
		// store first letter in each word in ideas as a key of suffix of word
		// like this [{c -> offee }, {d -> onuts},......]
		unordered_map<char, unordered_set<string>>words;
		for (string& s : ideas) {
			words[s[0]].insert(s.substr(1, s.size()));
		}
		long long numberOfValidNames = 0;
		// two loops to count numberOfValidNames
		for (auto& c1 : words) {
			for (auto& c2 : words) {
				int intersection = 0;
				if (c1 != c2) {// if the two letters  differ, iterate to count how many suffixes found in both  two groups
					for (auto& word : c1.second) {
						if (c2.second.find(word) != c2.second.end()) {
							intersection++;
						}
					}// numberOfDistinctWords in each group is => (sizeOfGroup - numberOfSharedNames)
					int validInC1 = c1.second.size() - intersection;
					int validInC2 = c2.second.size() - intersection;
					// So the numberOfValidNames is multiplication of numberOfDistinctWords in two groups 
					numberOfValidNames += validInC1 * validInC2;
				}
			}
		}
		return numberOfValidNames;
	}
};