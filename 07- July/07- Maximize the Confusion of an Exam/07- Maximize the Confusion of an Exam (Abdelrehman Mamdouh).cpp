class Solution
{
public:

    int get_mx (string& s, int k, char c)
    {
        int n = s.size (), l = 0, r = 0, count = 0, mx = 1;
        // use two pointers that keep count of char c and if this letter is not c 
        // we decrease k by one and keep moving with r 
        // if k reaches zero we move the l towards r and if s[l] was not equal to c
        // we then increase k by one and can move with r again
        // we use count to keep track of all valid indices and then get the max count
        while (r < n)
        {
            // keep moving if equal
            if (s[r] == c)
                count++, r++;
            // decrease k if s[r] is not equal to c
            else if (k > 0)
                count++, k--, r++;
            // move l towards r and add k if the s[l] was not equal to c
            else
                mx = max (mx, count), k += (s[l++] != c), count--;
        }
        mx = max (mx, count);
        return mx;
    }

    int maxConsecutiveAnswers (string answerKey, int k)
    {
        // get max consecutive T, get max consecutive F
        return max (get_mx (answerKey, k, 'T'), get_mx (answerKey, k, 'F'));
    }
};