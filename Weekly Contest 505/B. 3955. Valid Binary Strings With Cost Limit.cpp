// Approach : Recursion
// TC : O(2 ^ n)
// SC : O(n + n)
class Solution
{
public:
    void f(int ind, string &s, int cost, int n, int k, vector<string> &ans)
    {
        if (ind == n)
        {
            if (cost <= k)
                ans.push_back(s);
            return;
        }

        // keep 0
        f(ind + 1, s, cost, n, k, ans);

        // try 1
        if ((ind - 1 < 0) || (ind - 1 >= 0 && s[ind - 1] != '1'))
        {
            s[ind] = '1';
            f(ind + 1, s, cost + ind, n, k, ans);
            s[ind] = '0';
        }
    }

    vector<string> generateValidStrings(int n, int k)
    {
        vector<string> ans;
        string s(n, '0');
        f(0, s, 0, n, k, ans);
        return ans;
    }
};