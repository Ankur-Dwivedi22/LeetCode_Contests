// Approach : Dynamic Programming
// TC : O(n)
// SC : O(1)
class Solution
{
public:
    using ll = long long;
    ll m = 1e18;
    long long maxTotal(vector<int> &nums, string s)
    {
        ll mx0 = 0, mx1 = -m;
        if (s[0] == '1')
        {
            mx1 = nums[0];
            mx0 = -m;
        }

        for (int i = 1; i < nums.size(); i++)
        {
            ll next_mx0 = -m, next_mx1 = -m;
            if (s[i] == '0')
            {
                next_mx0 = max(mx0, mx1);
            }
            else
            {
                next_mx1 = max(mx0, mx1) + nums[i];
                ll c1 = (mx0 != -m) ? mx0 + nums[i - 1] : -m;
                ll c2 = mx1;
                next_mx0 = max(c1, c2);
            }

            mx0 = next_mx0;
            mx1 = next_mx1;
        }

        ll ans = max(mx0, mx1);
        return ans;
    }
};