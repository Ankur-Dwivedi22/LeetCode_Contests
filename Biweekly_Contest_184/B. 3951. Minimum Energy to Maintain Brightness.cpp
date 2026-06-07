// Approach : Implementation
// TC : O(n * logn)
// SC : O(n)
class Solution
{
public:
    long long minEnergy(int n, int brightness, vector<vector<int>> &intervals)
    {
        long long bulbs = (brightness + 2) / 3;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> v;
        for (auto it : intervals)
        {
            if (v.empty())
            {
                v.push_back(it);
            }
            else
            {
                auto prev = v.back();
                if (it[0] <= prev[1])
                {
                    v.pop_back();
                    v.push_back({prev[0], max(it[1], prev[1])});
                }
                else
                {
                    v.push_back(it);
                }
            }
        }

        long long t = 0;
        for (auto it : v)
        {
            t += (it[1] - it[0] + 1);
        }

        long long ans = t * 1ll * bulbs;
        return ans;
    }
};