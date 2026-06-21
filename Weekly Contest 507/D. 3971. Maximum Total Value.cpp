class Solution
{
public:
    const int M = 1e9 + 7;
    bool check(int x, vector<int> &v, vector<int> &d, int m)
    {
        int ct = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] < x)
                continue;
            int k = 1 + (v[i] - x) / d[i];
            ct += k;
            if (ct >= m)
                return true;
        }
        return false;
    }

    int maxTotalValue(vector<int> &value, vector<int> &decay, int m)
    {
        int lo = 1, hi = 1e9;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (check(mid, value, decay, m))
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        int t = hi;
        long long ct = 0, ans = 0;

        for (int i = 0; i < value.size(); i++)
        {
            if (value[i] < t)
                continue;
            int k = 1 + (value[i] - t) / decay[i];
            ct += k;
            long long sum = (k * (2ll * value[i] - (k - 1) * 1ll * decay[i])) / 2;
            ans = (ans + sum) % M;
        }

        int extra = ct - m;
        ans = (ans - ((extra * 1ll * t) % M) + M) % M;

        return (int)ans;
    }
};