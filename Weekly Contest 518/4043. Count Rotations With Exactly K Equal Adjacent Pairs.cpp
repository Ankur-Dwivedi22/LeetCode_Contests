// TC : O(N * N)
// SC : O(1)
class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size();
        s += s;
        int ans = 0;
        for(int i=0; i<n; i++){
            int ct = 0;
            int j=i;
            while(j <= i+n-2){
                if(s[j] == s[j+1]) ct++;
                j++;
            }
            if(ct == k) ans++;
        }

        return ans;
    }
};
