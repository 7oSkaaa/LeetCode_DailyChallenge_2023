// Author: Osama Ayman
class Solution {
    public String addBinary(String a, String b) {
        // set b to be the shortest
        if(a.length() < b.length()){
            String tmp = b;
            b=a;
            a=tmp;
        }
        int alen = a.length();
        int blen = b.length();
        int[] res = new int[alen+1];
        int aindx = alen-1;
        int bindx = blen-1;
        int resindx = res.length-1;
        while(bindx >= 0){
            char achar = a.charAt(aindx--);
            char bchar = b.charAt(bindx--);
            int sum = achar-'0' + bchar-'0' + res[resindx];
            if(sum==3){
                res[resindx]=1;
                res[--resindx]=1;
            }
            else if(sum==2){
                res[resindx]=0;
                res[--resindx]=1;
            }
            else if(sum==1){
                res[resindx]=1;
                resindx--;
            }
            // sum=0
            else {
                res[resindx]=0;
                resindx--;
            }
        }

        while(aindx >= 0){
            int sum = a.charAt(aindx--)-'0' + res[resindx];
            if (sum==2){
                res[resindx]=0;
                res[--resindx]=1;

            }
            else if (sum==1){
                res[resindx]=1;
                resindx--;
            }
            else{
                res[resindx]=0;
                resindx--;
            }
        }
        StringBuilder sb = new StringBuilder();
        for(int r: res){
            // don't append zeros at the begining
            if(sb.length() == 0 && r==0) continue;
            sb.append(r);
        }
        return sb.length() > 0 ? sb.toString() : "0";
    }
}