class Solution
{
public:
    long long dp[20][10][2][2];

    long long dp_func(int ind, int prev, string &s, int k, bool tight, bool lz)
    {
        if (ind == s.size())
        {
            return 1ll;
        }

        if (dp[ind][prev][tight][lz] != -1)
            return dp[ind][prev][tight][lz];

        int lb = 0;
        int ub = (tight ? s[ind] - '0' : 9);
        long long ans = 0;
        for (int dig = lb; dig <= ub; dig++)
        {
            if (lz == true)
            {
                ans += dp_func(ind + 1, dig, s, k, (tight && dig == ub), dig == 0);
                continue;
            }
            int diff = abs(dig - prev);
            if (diff > k)
                continue;
            ans += dp_func(ind + 1, dig, s, k, (tight && dig == ub), false);
        }

        return dp[ind][prev][tight][lz] = ans;
    }

    long long goodIntegers(long long l, long long r, int k)
    {
        string left = to_string(l - 1);
        string right = to_string(r);
        memset(dp, -1, sizeof(dp));
        long long r_val = dp_func(0, 0, right, k, true, true);
        memset(dp, -1, sizeof(dp));
        long long l_val = dp_func(0, 0, left, k, true, true);
        return r_val - l_val;
    }
};