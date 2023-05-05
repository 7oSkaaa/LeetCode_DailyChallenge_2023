// Author : Ibrahim Khalid
class Solution {
public:
// check if letter is one of Vowel letters
bool vowel(char c){
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
        return true;
    }
    return false;
}

    int maxVowels(string s, int k) {
        // (result) store maximum number of vowel letters in any substring
        int mx=0;
        // store number of vowel letters in any substring
        int cnt=0;
        // pointer to indicate first letter of substring 
        int begin=0;
        // to boolen to pointer (begin) if  letter is one of Vowel letters
        int flog=0;
        // check to index 0 
        if(vowel(s[begin])){
                flog=1;
                cnt++;
        }

        for(int i=1;i<=s.size();i++){
            if(i+1<=k){
                // if letter is one of Vowel letters increase number of vowel letters in any substring
                if(vowel(s[i])){
                            cnt++;
                    }
            }
            else{
                // comparison between mx and Present cnt 
                mx=max(cnt,mx);
                // shift begin and decrease cnt if letter is one of Vowel letters
                if(flog){
                    cnt--;
                }
                begin++;
                flog=0;
                // check to  next index to pointer begin  
                if(vowel(s[begin]))flog=1;
                    // check to  presnt index 
                if(vowel(s[i])){
                            cnt++;
                    }
            }
        }
        return mx;
    }
};
