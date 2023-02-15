// Author: Osama Ayman
class Solution {
    public List<Integer> addToArrayForm(int[] num, int k) {
        List<Integer> res = new ArrayList<>();
        int idx=num.length-1;
        int carry=0, sum=0;
        // while there are 2 numbers to be added, do the following
        while(k>0 && idx>=0){
        // k%10 will gives the ones digit of k
            sum = k%10 + num[idx] + carry;
            carry = sum/10;
            res.add(sum%10);
            // k/10 will remove the last digit of k
            k/=10;
            idx--;
        }
        // now, if there is a number that is not consumed it will only be k or num array (not both).
        sum=0;
        // calculating result as k is the only number left
        while(k>0){
            sum=k%10 + carry;
            res.add(sum%10);
            carry = sum/10;;
            k/=10;
        }
        // calculating result as num is the only number left
        while(idx>=0){
            sum=num[idx--] + carry;
            res.add(sum%10);
            carry = sum/10;
        }
        // don't forget to add the carry at the end
        if(carry>0)  res.add(carry);
        // reverse it to get the correct result, because adding in the list add the number at the end and we want to add at the begining.
        Collections.reverse(res);
        return res;

    }
}
