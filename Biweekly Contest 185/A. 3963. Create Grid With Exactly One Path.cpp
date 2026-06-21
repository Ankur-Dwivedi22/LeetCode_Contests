class Solution
{
public:
    vector<string> createGrid(int m, int n)
    {
        vector<string> ans(m);
        for (int i = 0; i < m - 1; i++)
        {
            string s(n, '#');
            s[0] = '.';
            ans[i] = s;
        }
        string s(n, '.');
        ans[m - 1] = s;
        return ans;
    }
};