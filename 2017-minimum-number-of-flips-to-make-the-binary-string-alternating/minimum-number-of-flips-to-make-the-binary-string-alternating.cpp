class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string ss = s + s;

        int diff1 = 0, diff2 = 0;
        int ans = INT_MAX;

        for(int i = 0; i < ss.size(); i++) {

            if(ss[i] != (i % 2 ? '1' : '0')) diff1++;
            if(ss[i] != (i % 2 ? '0' : '1')) diff2++;

            if(i >= n) {
                if(ss[i-n] != ((i-n) % 2 ? '1' : '0')) diff1--;
                if(ss[i-n] != ((i-n) % 2 ? '0' : '1')) diff2--;
            }

            if(i >= n-1) {
                ans = min(ans, min(diff1, diff2));
            }
        }

        return ans;
    }
};