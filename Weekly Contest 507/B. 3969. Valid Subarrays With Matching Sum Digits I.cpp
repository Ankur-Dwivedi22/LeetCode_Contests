class Solution
{
public:
    int countValidSubarrays(vector<int> &nums, int x)
    {
        int ct = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            long long sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                long long temp = sum;
                int l = temp % 10, f;
                while (temp > 0)
                {
                    f = temp % 10;
                    temp /= 10;
                }
                if (f == x && l == x)
                    ct++;
            }
        }

        return ct;
    }
};