class Solution
{
public:
    using ll = long long;
    ll M = 1e9 + 7;

    ll power(ll b, ll e)
    {
        b = b % M;
        ll res = 1;
        while (e > 0)
        {
            if (e % 2 == 1)
                res = (res * b) % M;
            b = (b * b) % M;
            e /= 2;
        }
        return res;
    }

    ll nCr(ll n, ll r)
    {
        if (r < 0 || r > n)
            return 0;
        if (r == 0)
            return 1;

        if (r > n / 2)
            r = n - r;
        ll num = 1;
        ll den = 1;
        for (int i = 0; i < r; i++)
        {
            num = (num * (n - i)) % M;
            den = (den * (i + 1)) % M;
        }

        return (num * power(den, M - 2)) % M;
    }

    int countValidSequences(int n, int k)
    {
        ll total = nCr(n - 1, k - 1);
        ll s = n - k;
        if (s % 2 == 1)
            return total;
        s /= 2;
        ll odd = nCr(s + k - 1, k - 1);
        return (total - odd + M) % M;
    }
};