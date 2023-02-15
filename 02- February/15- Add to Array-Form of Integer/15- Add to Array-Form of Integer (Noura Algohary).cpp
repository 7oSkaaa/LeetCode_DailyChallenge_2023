// Author: Noura Algohary
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
      int kNum, i = num.size()-1;  // Begin from the right side of the array

      // Iterate through the digits of K
      while(k!=0)
      {
          if(i<0) {num.insert(num.begin(),1,0); i++;}
		  
          // Getting the first bit of K (k%10)
          // Adding the Ith digit of k to the Ith digit from right of the array
          kNum = num[i] + (k%10);

          // One element of the array contains one digit so,
          num[i] = kNum%10;

          //If a summation of two digits is more than one digit, Add the second digit to the K as carry. 
          // But first divide K by 10 to get rid of the first digit - which we added to array already-.
          k/=10;
          k+=kNum/10;
          
          i--;
      }
    return num;
    }
};