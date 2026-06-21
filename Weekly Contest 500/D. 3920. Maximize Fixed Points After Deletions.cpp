class Solution
{
public:
    int maxFixedPoints(vector<int> &nums)
    {
        int n = nums.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            int diff = i - nums[i];
            if (diff >= 0)
            {
                v.push_back({diff, nums[i]});
            }
        }
        sort(v.begin(), v.end());
        vector<int> lis;
        for (auto it : v)
        {
            int val = it.second;
            auto ptr = lower_bound(lis.begin(), lis.end(), val);
            if (ptr == lis.end())
            {
                lis.push_back(val);
            }
            else
            {
                *ptr = val;
            }
        }

        int ans = lis.size();
        return ans;
    }
};