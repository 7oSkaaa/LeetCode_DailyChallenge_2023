// Author: Mina Magdy

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        return is_sorted(words.begin(), words.end(), [&](string& a, string &b) -> bool {
            int n = min(a.size(), b.size());
            for (int i = 0; i < n; i++) {
                int id1 = order.find(a[i]);
                int id2 = order.find(b[i]);
                if (id1 != id2) return id1 < id2;
            }
            return a.size() < b.size();
        });
    }
};
/*
    is_sorted( first iterator, last iterator, callback comp )
    - is a built-in function 
    - first iterator : words.begin()
    - last iterator : words.end()
    - compare : HERE IS THE MAGIC!!
    to define our custom compare function we need,
    bool function takes 2 arguments string 'a', string 'b'
    for each character in 'a' compare it with its corresponding character in 'b',
    by comparing their position in 'order' string 
    (let's call them 'id1' and 'id2' for 'a' and 'b' respectively) 
    once they are different, return id1 < id2
    otherwise and after finishing the iteration,
    return a.size() < b.size() to ensure that the shorter is the first 
*/

/*
    you can define comp as a normal function and pass it to 'is_sorted' 
    (the name of the function without '()' is called 'callback function') such as:

    `
    bool comp(string &a, string &b) {
        return a < b;
    }
    is_sorted(words.begin(), words.end(), comp);
    `
*/
