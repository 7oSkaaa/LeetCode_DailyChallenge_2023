// author : ibrahim khalid
class SmallestInfiniteSet {
public:
  // create set to store number 1 from 1000
set<int>s;
  // create value increase by 1
int n;
    SmallestInfiniteSet() {
            // Initial value equal 1
            n=1;
    }

    int popSmallest() {
        SmallestInfiniteSet();
      // add n
        s.insert(n);
      // increae to store after pop small element
        n++;
      // x equal smallest element
        int x=* s.begin();
      // pop
        s.erase(x);
        return x;

    }

    void addBack(int num) {
        // if num less than or equal to n --> store in set
        if(num<=n){
            s.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
