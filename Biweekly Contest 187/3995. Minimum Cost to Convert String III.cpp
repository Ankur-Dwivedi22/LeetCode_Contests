class Solution
{
public:
    int solve(int ind, string &s, string &t, vector<vector<string>> &rules,
              vector<int> &costs, vector<int> &dp)
    {
        if (ind == s.size())
        {
            return 0;
        }

        if (dp[ind] != -1)
            return dp[ind];
        int ans = 1e9;
        if (s[ind] == t[ind])
        {
            ans = 0 + solve(ind + 1, s, t, rules, costs, dp);
        }
        bool f = false;
        for (int i = 0; i < rules.size(); i++)
        {
            auto rule = rules[i];
            int sz = rule[0].size();
            if (ind + sz <= s.size())
            {
                int ct = 0, fl = 1;
                for (int j = 0; j < rule[0].size(); j++)
                {
                    if (rule[0][j] == '*')
                        ct++;
                    if ((rule[0][j] == '*' || s[ind + j] == rule[0][j]) &&
                        (t[ind + j] == rule[1][j]))
                        continue;
                    fl = false;
                    break;
                }
                if (fl)
                {
                    ans = min(ans, ct + costs[i] +
                                       solve(ind + rule[0].size(), s, t, rules,
                                             costs, dp));
                }
            }
        }

        return dp[ind] = ans;
    }
    int minCost(string source, string target, vector<vector<string>> &rules,
                vector<int> &costs)
    {

        int n = source.size();
        vector<int> dp(n + 1, -1);
        int ans = solve(0, source, target, rules, costs, dp);
        return (ans >= 1e9 ? -1 : ans);
    }
};