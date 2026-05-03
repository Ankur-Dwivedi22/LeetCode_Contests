class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        for(int i=0; i<n; i++){
            int ct = 0;
            for(int j=i+1; j<n; j++){
                if((nums[i] % 2) != (nums[j] % 2)) ct++;
            }
            ans[i] = ct;
        }
        return ans;
    }
};