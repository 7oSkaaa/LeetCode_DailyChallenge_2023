//Author : Nayra Mohammed 

// Can be solved in an easier way but we live to suffer OwO
#define MemS(s, x) memset(s, x, sizeof(s))
class Solution {
public:
   /*
    Gonna solve that problem in a recursive way rather than the iterative form ..
    
    As we saw in problem description,The Tribonacci sequence is as follow:
    T0 = 0, T1 = 1, T2 = 1, and Tn = Tn-1 + Tn-2 + Tn-3
    so to get Tn we can imagine the process :
                                                             Tn
                                               /              |              \
                                          Tn-1   +           Tn-2      +      Tn-3
                                      /    |    \        /    |    \       /    |     \  
                                    Tn-2  Tn-3  Tn-4   Tn-3  Tn-4  Tn-5  Tn-4  Tn-5  Tn-6
                                   ....................................................
                                   till reaching T0 or T1 or T2 which are our base values, 0,1 and 1 respectifully..
    
    We can obviously see that in some process like in getting Tn-3 or Tn-1 or Tn-2 some of them need to get the value that was calculated before   
    To make our recusive call to calculate any value more effecient specially in time complexity !! we gona use Memorization.
    So, in calculating a specific value if it needs a value that was calculated before we return it immediately "rater than calculating it all over again".
    Otherwise, the needed value needs to be calculated first so we calculate it and store its value for further process 
    */
  
    int dp[38]; // Our Memorization array
  
    int Calc(int n){
       
        if(n <= 2) // the elements are our base values : T0,  T1, T2
            return(!n ? 0 : 1); //T0 = 0,T1 = T2 = 1
     
        if(dp[n] != -1) // if the needed element was calculated before , return its value
            return dp[n];

        return dp[n] = Calc(n-1) + Calc(n-2) + Calc(n-3); //calculate Tn value using equation : Tn-1 + Tn-2 + Tn-3       
    }
  
    int tribonacci(int n) {
        MemS(dp,-1); // initialize our memorization array (-1 refers to this element wasn't processed before)
        
        return Calc(n); // Calculate element's value ans return it's value as the requested answer
    }
};
