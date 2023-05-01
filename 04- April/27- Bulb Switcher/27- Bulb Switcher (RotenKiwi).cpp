// Author: RotenKiwi

class Solution {
 public:
  int bulbSwitch(int num) {
    if (0 == num) { return 0; }  // Avoid zero divide  
    int n = (num / 2) + 1;       // Initial estimate, never low  
    int n1 = (n + (num / n)) / 2;  
    while (n1 < n) {  
        n = n1;  
        n1 = (n + (num / n)) / 2;  
    } // end while  
    return n;  
  }
};
