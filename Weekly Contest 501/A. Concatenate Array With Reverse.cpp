// Approach : Simulation
// TC : O(N)
// SC : O(2 * N)
class Solution
{
public:
    vector<int> concatWithReverse(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans = nums;
        for (int i = n - 1; i >= 0; i--)
        {
            ans.push_back(nums[i]);
        }

        return ans;
    }
};