class Solution
{
public:
    long long maximumValue(int n, int s, int m)
    {
        long long ans = s;
        if (n == 1)
        {
            return ans;
        }

        ans += (n / 2) * 1ll * m;
        ans -= 1ll * (n - 1) / 2;

        return (n % 2 == 0 ? ans : ans + 1);
    }
};