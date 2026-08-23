class Solution
{
public:
    string binary(int n)
    {
        string ans = "";
        for (int i = 7; i >= 0; i--)
        {
            int dig = (n >> i) & 1;
            ans += (dig ? "1" : "0");
        }
        // cout<<ans<<"\n";
        return ans;
    }

    bool isPalindrome(string s)
    {
        int l = 0, r = s.size() - 1;
        while (l < r)
        {
            if (s[l] != s[r])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    bool isPalindromic(string s)
    {
        string res = "";
        for (char c : s)
        {
            string s = binary((int)c);
            res += s;
        }
        // cout<<res<<"n";
        return isPalindrome(res);
    }
};