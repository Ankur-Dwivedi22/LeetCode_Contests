class Solution
{
public:
    vector<int> minCost(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        vector<int> p(n, 0), s(n, 0);
        p[1] = 1;
        for (int i = 2; i < n; i++)
        {
            int ind = i - 1;
            int val1 = abs(nums[ind] - nums[ind - 1]);
            int val2 = abs(nums[ind] - nums[ind + 1]);
            if (val2 < val1)
            {
                p[i] = p[i - 1] + 1;
            }
            else
            {
                p[i] = p[i - 1] + val2;
            }
            // cout<<p[i]<<" ";
        }
        // cout<<"\n";
        s[n - 2] = 1;
        for (int i = n - 3; i >= 0; i--)
        {
            int ind = i + 1;
            int val1 = abs(nums[ind] - nums[ind - 1]);
            int val2 = abs(nums[ind] - nums[ind + 1]);
            if (val1 <= val2)
            {
                s[i] = s[i + 1] + 1;
            }
            else
            {
                s[i] = s[i + 1] + val1;
            }
            // cout<<s[i]<<" ";
        }

        vector<int> ans;
        for (auto it : queries)
        {
            int l = it[0], r = it[1];
            int val = 0;
            if (l < r)
            {
                val = p[r] - p[l];
            }
            else
            {
                val = s[r] - s[l];
            }
            ans.push_back(val);
        }

        return ans;
    }
};