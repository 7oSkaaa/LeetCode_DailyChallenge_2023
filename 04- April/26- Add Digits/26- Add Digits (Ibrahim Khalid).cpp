// author : Ibrahim Khalid
class Solution {
public:
    int addDigits(int num) {
        // str to convert num(int) to string to can count digits
        string str=to_string(num);
        int sum;
        // if Digitalis number equal 1 break from loop
        while(str.size()!=1){
            sum=0;
            // to summation digits
        for(int i=0;i<str.size();i++){
            //to convert from char to int
            sum+=(str[i]-'0');
        }
        // to convert summation to string to check  digitalis number
         str=to_string(sum);
         
        }
        return sum;
    }
};
