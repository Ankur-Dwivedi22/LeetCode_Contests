// TC : O(m * n * n)
// SC : O(n)
class Solution {
public:
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        int m = grid.size() , n = grid[0].size();
        vector<int> dp(n, 1);
        int ans = 0;

        for(int j=0; j<n; j++){
            for(int c=0; c<j; c++){
                bool fl = true;
                for(int i=0; i<m; i++){
                    if(abs(grid[i][j] - grid[i][c]) > limit){
                        fl = false;
                        break;
                    }
                }
                if(fl){
                    dp[j] = max(dp[j], dp[c] + 1);
                }
            }
            ans = max(ans, dp[j]);
        }

        return ans;
    }
};