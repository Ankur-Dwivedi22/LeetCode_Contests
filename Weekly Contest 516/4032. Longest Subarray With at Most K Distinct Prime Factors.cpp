class Solution
{
public:
    int longestSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();
        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            mx = max(mx, nums[i]);
        }

        vector<int> spf(mx + 1);
        for (int i = 1; i <= mx; i++)
        {
            spf[i] = i;
        }

        for (int i = 2; i * i <= mx; i++)
        {
            if (spf[i] == i)
            {
                for (int j = i * i; j <= mx; j += i)
                {
                    if (spf[j] == j)
                    {
                        spf[j] = i;
                    }
                }
            }
        }

        unordered_map<int, int> mp;
        int l = 0, ans = 0;
        for (int r = 0; r < n; r++)
        {
            int x = nums[r];
            while (x > 1)
            {
                int p = spf[x];
                mp[p]++;
                while (x % p == 0)
                {
                    x /= p;
                }
            }

            while (mp.size() > k)
            {
                int y = nums[l];
                while (y > 1)
                {
                    int p = spf[y];
                    mp[p]--;

                    if (mp[p] == 0)
                        mp.erase(p);
                    while (y % p == 0)
                    {
                        y /= p;
                    }
                }
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};