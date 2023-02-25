//Author : Nayra Mohammed

class Solution
{
  /* 
    - Main Solution idea : Arithmatic Sequence.
      All we need is to find the first and last odd elements in the range of [low,high].
      Then we use the formula : no.terms in an arithmetic sequence = ((last term - first term) / d ) + 1
      d-> refers to the common difference between every  consecutive elements which here equals to 2
  */
public:
    int countOdds(int low, int high)
    {
        
        low += (low % 2 == 0); //In case low is odd we do nothing as it's our first odd term, otherwise we need to add one to get the first odd after low 
        high -= (high % 2 == 0);//In case high is odd we do nothing as it's our last odd term, otherwise we need to subtract one to get the last odd before high 

        return ((high - low) / 2) + 1; // return number of odd elements "using
    }
};
