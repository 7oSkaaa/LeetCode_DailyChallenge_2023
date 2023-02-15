// Author: Osama Ayman
class Solution {
    public List<Integer> addToArrayForm(int[] num, int k) {
        List<Integer> res = new ArrayList<>();
        int idx=num.length-1;
        int carry=0, sum=0;
        while(k>0 && idx>=0){
            sum = k%10 + num[idx] + carry;
            carry = sum/10;
            res.add(sum%10);
            k/=10;
            idx--;
        }
        sum=0;
        while(k>0){
            sum=k%10 + carry;
            res.add(sum%10);
            carry = sum/10;;
            k/=10;
        }

        while(idx>=0){
            sum=num[idx--] + carry;
            res.add(sum%10);
            carry = sum/10;
        }

        if(carry>0)  res.add(carry);

        Collections.reverse(res);
        return res;

    }
}