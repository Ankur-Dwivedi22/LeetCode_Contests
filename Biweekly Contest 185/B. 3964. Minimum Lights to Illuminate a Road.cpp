class Solution
{
public:
    int minLights(vector<int> &lights)
    {
        int n = lights.size();
        vector<int> v(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (lights[i] == 0)
                continue;
            int l = max(0, i - lights[i]);
            int r = min(n - 1, i + lights[i]);
            v[r] += 1;
            if (l - 1 >= 0)
                v[l - 1] -= 1;
        }

        for (int i = n - 2; i >= 0; i--)
        {
            v[i] += v[i + 1];
        }

        int ans = 0, ct0 = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i] == 0)
            {
                ct0++;
            }
            else
            {
                ans += (ct0 + 2) / 3;
                ct0 = 0;
            }
        }

        ans += (ct0 + 2) / 3;
        return ans;
    }
};