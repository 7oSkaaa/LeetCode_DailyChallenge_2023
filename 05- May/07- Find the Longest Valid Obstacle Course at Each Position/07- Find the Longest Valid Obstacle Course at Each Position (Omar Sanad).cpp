// author : Omar Sanad

// To solve this problem, it's better for you to be familiar with getting LIS (Longest Increasing Subsequence) in O(nLog(n))

// This video really helped me understand it a couple months ago: https://youtu.be/on2hvxBXJH4

// In this problem at each index we will search for the longest non decreasing subsequence
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& ob) {
        // declare n -> the size of the input array
        int n = ob.size();

        // declare two vectors 
        // One vector to store some information about length of the longest increasing subsequence at each idx
        // elements in temp are sorted in non-decreasing order
        // the other vector to store the answer
        vector < int > temp = {ob.front()}, Answers(n, 1);

        for (int i = 1, idx; i < n; i++){
            // check where is the best position for this element to insert in the temp variable
            idx = upper_bound(temp.begin(), temp.end(), ob[i]) - temp.begin();

            // if this element is greater than all elements in temp, then add it to temp
            if (idx == temp.size()) {
                temp.push_back(ob[i]);
                Answers[i] = temp.size();
            }
            // else then replace it with the first element that is greater than it, as this will maximize the LIS
            else{
                temp[idx] = ob[i];
                Answers[i] = idx + 1;
            }
        }


        // return the answers vector
        return Answers;
    }
};
