//Author: Mohamed Ibrahim

class Solution {
public:

int minFlipsMonoIncr(string s) {
int o = 0,z = 0,cnt = 0;
//iterate through each character in the input string
for(auto i : s){
//if the current character is a '1', increment the variable 'o'
if(i == '1') o++;
//if the current character is a '0' and variable 'o' is greater than 0, increment variable 'z'
else if(o>0) z++;
//if variable 'o' is less than or equal to variable 'z'
if(o <= z){
//increment variable 'cnt' by the value of variable 'o'
cnt += o;
//reset variables 'o' and 'z' to 0
o = 0;
z = 0;
}
}
//increment variable 'cnt' by the minimum of the values of variables 'o' and 'z'
cnt += min(o , z);
//return the final value of variable 'cnt'
return cnt;
}
};
/*This function is counting the minimum number of flips required to convert a binary string s to a monotonically increasing string.
It's counting the number of '0's before the first '1' and the number of '1's after the last '0'.*/