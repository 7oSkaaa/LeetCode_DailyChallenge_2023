// Author : Salman Mohamed 

// The whole idea i think of the problem is how to add big int by old method (we learned in primary school
//-I don't know what the name of it 😂 -)
//Adding numbers in this method just to add every digit with its corrsponding digit in the other number
// like that:
//     |
//     v
// 1 9 2
//+
// 1 3 3
//     5
//then we go to the next number 
//   |
//   v
// 1 9 2
//+
// 1 3 3
//     5
//here a small problem came to the scene which  9+3 =12 and we 
// was suppose to put one digit only so what we can do?? 
//this small problem can be solved by carry which is as follow
// we put 2 in and take the 1 as carry to the next operation 
// 1 |
//   v
// 1 9 2
//+
// 1 3 3
//   2 5
// and etc ..
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
    vector<int> num2; 
	// here i just convert the int to array of its digits to be easy for me to do the operations;

    while(k){
        num2.push_back(k%10);
        k/=10;
    }   
    vector<int> ans; 
//	here i reverse the arrays as we suppose to start adding
//      from right and i like to loop from 0 which is left

    reverse(num.begin(),num.end());
    // reverse(num2.begin(),num2.end())

    if(num.size()>num2.size()){
        int carry=0;
       
        for(int i =0;i<num2.size();i++){
            int sum=num2[i]+num[i]+carry;
            if(sum>9){
                ans.push_back(sum%10);
                sum/=10;
                carry=sum; 
            }
            else {
                ans.push_back(sum%10);
                carry=0;
            }
        }



        for(int i =num2.size() ; i<num.size();i++){
            int sum=num[i]+carry;
            if(sum>9){
                ans.push_back(sum%10);
                sum/=10;
                carry=sum; 
            }
            else {
                ans.push_back(sum%10);
                carry=0;
            }
        }
        if( carry) ans.push_back(carry);
    }

    else {
        int carry=0;
        
        for(int i =0;i<num.size();i++){
            int sum=num2[i]+num[i]+carry;
            if(sum>9){
                ans.push_back(sum%10);
                sum/=10;
                carry=sum; 
            }
            else {
                ans.push_back(sum%10);
                carry=0;
            }
        }
        for(int i =num.size() ; i<num2.size();i++){
            int sum=num2[i]+carry;
            if(sum>9){
                ans.push_back(sum%10);
                sum/=10;
                carry=sum; 
            }
            else {
                ans.push_back(sum%10);
                carry=0;   
            }

        }






            if(carry) ans.push_back(carry);
    }


    reverse(ans.begin(),ans.end());
    return ans; 
    }
};
