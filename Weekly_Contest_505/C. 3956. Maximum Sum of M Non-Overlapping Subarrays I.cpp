// Approach : DP + Monotonic Dqueue
// TC : O(N + N + M * N + M) => O(M * N)
// SC : O(N + M * N) => O(M * N)
class Solution
{
public:
    using ll = long long;

    long long maximumSum(vector<int> &nums, int m, int l, int r)
    {
        int n = nums.size();
        vector<ll> pre(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            pre[i] = pre[i - 1] + nums[i - 1];
        }

        ll ans = -1e18;
        vector<vector<ll>> dp(m + 1, vector<ll>(n + 1, -1e18));
        for (int i = 0; i <= n; i++)
        {
            dp[0][i] = 0;
        }

        for (int j = 1; j <= m; j++)
        {
            deque<int> dq;
            for (int i = 1; i <= n; i++)
            {
                int p = i - l;
                if (p >= 0)
                {
                    ll p_val = dp[j - 1][p] - pre[p];
                    while (!dq.empty() &&
                           (dp[j - 1][dq.back()] - pre[dq.back()]) <= p_val)
                    {
                        dq.pop_back();
                    }
                    dq.push_back(p);
                }

                while (!dq.empty() && dq.front() < i - r)
                {
                    dq.pop_front();
                }

                ll c1 = dp[j][i - 1];
                ll c2 = -1e18;

                if (!dq.empty())
                {
                    ll best_val = dp[j - 1][dq.front()];
                    if (best_val != -1e18)
                    {
                        c2 = max(c2, best_val + pre[i] - pre[dq.front()]);
                    }
                }

                dp[j][i] = max(c1, c2);
            }
        }

        for (int j = 1; j <= m; j++)
        {
            ans = max(ans, dp[j][n]);
        }

        return ans;
    }
};