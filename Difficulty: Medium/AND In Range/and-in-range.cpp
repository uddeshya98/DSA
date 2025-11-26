class Solution {
  public:
    int andInRange(int l, int r) {
        int v = 0;
        while( l != r){
            l >>= 1;
            r >>= 1;
            v++;
        }
        return l << v;
        
    }
};
