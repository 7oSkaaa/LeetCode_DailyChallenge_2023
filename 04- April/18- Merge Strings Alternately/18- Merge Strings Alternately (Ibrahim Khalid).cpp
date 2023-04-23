//Author : Ibrahim Khalid
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        // create two pointers to each word
        int l1=0,r1=word1.size();
        int l2=0,r2=word2.size();
        // to store result
        string res;

        while(l1<r1||l2<r2){
            // iterate of the two strings until the end of both of them
            if(l1<r1&&l2<r2){
                res+=word1[l1];
                res+=word2[l2];
                l1++;l2++;
            }
            // if word1 end ,we continue with word2;
            else if(l1==r1&&l2<r2){
                res+=word2.substr(l2,r2);
                break;
            }
            // if word1 end , we continue with word1;
            else if(l1<r1&&l2==r2){
                res+=word1.substr(l1,r1);
                break;
            }
        }
        return res;

    }
};