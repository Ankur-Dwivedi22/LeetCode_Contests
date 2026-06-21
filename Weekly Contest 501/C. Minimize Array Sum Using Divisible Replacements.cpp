// Approach : Similar to sieve
// TC : O(N) + O(N) + O(M * logM) + O(N) , M = maximum number -> O(M * logM)
// SC : O(M) + O(M) -> O(M)
class Solution
{
public:
    long long minArraySum(vector<int> &nums)
    {
        int MAXN = *max_element(nums.begin(), nums.end()) + 1;
        vector<int> freq(MAXN, 0);
        vector<int> div(MAXN);
        for (int el : nums)
        {
            div[el] = el;
            freq[el]++;
        }

        for (int i = 1; i < MAXN; i++)
        {
            if (freq[i] > 0)
            {
                for (int j = i; j < MAXN; j += i)
                {
                    if (freq[j] > 0 && div[j] == j)
                    {
                        div[j] = i;
                    }
                }
            }
        }
        long long ans = 0;
        for (int el : nums)
        {
            ans += div[el];
        }

        return ans;
    }
};