// TC : O(m * n * 2 ^ (m * n))
// SC : O(m * n) + O(n)
class Solution
{
public:
    using ll = long long;

    ll maxPaths(int r, int c, int m, int n, vector<ll> dp)
    {
        for (int i = r; i < m; i++)
        {
            int sc = (i == r ? c : 0);
            for (int j = sc; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    dp[j] = 1;
                }
                else
                {
                    ll up = (i > 0 ? dp[j] : 0);
                    ll left = (j > 0 ? dp[j - 1] : 0);
                    dp[j] = max(dp[j], up + left);
                }
            }
        }

        return dp[n - 1];
    }

    bool dfs(int r, int c, int m, int n, int k, vector<ll> &dp, vector<string> &ans)
    {
        if (r == m)
        {
            return dp[n - 1] == k;
        }
        ll mx = maxPaths(r, c, m, n, dp);
        if (mx < k)
        {
            return false;
        }

        if (mx == k)
        {
            return true;
        }

        int nr = r + (c + 1) / n;
        int nc = (c + 1) % n;
        if (!((r == 0 && c == 0) || (r == m - 1 && c == n - 1)))
        {
            ll prev = dp[c];
            dp[c] = 0;
            ans[r][c] = '#';

            if (dfs(nr, nc, m, n, k, dp, ans))
                return true;

            ans[r][c] = '.';
            dp[c] = prev;
        }

        ll prev = dp[c];
        ll up = (r > 0 ? dp[c] : 0);
        ll left = (c > 0 ? dp[c - 1] : 0);
        dp[c] = (r == 0 && c == 0) ? 1 : up + left;
        if (dfs(nr, nc, m, n, k, dp, ans))
            return true;
        dp[c] = prev;
        return true;
    }

    vector<string> createGrid(int m, int n, int k)
    {
        vector<string> ans(m, string(n, '.'));
        vector<ll> dp(n, 0);

        if (dfs(0, 0, m, n, k, dp, ans))
        {
            return ans;
        }

        return {};
    }
};