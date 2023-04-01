//Author: Nayra Mohammed

class Solution
{
public:
    /*
        - Gonna use lower bound func to find similar or greater value compared to x
        - If lower bound return an iterator pointing to the end of our container or a value greater than x
          then, the answer = -1
        - Otherwise we return the index in which we found x , "iterator - container.begin()"
    */
    int search(vector<int> &v, int x)
    {
        auto it = lower_bound(v.begin(), v.end(), x);
        return (it == v.end() || v[it - v.begin()] != x ? -1 : it - v.begin());
    }
};
