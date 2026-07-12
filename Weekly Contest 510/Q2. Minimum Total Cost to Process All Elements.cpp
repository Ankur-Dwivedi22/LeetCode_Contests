// TC : O(n)
// SC : O(1)
class Solution
{
public:
    using ll = long long;
    const ll M = 1e9 + 7;
    int minimumCost(vector<int> &nums, int k)
    {
        ll n = nums.size();
        ll r = k, ct = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= r)
            {
                r -= nums[i];
            }
            else
            {
                ll req = (nums[i] - r);
                ll val = (req + k - 1) / k;
                ct += val;
                r += (val * k);
                r -= nums[i];
            }
        }

        ll a = ct % M;
        ll b = (ct + 1) % M;

        if (a % 2 == 0)
            a /= 2;
        else
            b /= 2;

        ll ans = (a * b) % M;
        return ans;
    }
};
©leetcode