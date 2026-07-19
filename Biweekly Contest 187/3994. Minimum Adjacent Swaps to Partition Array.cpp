class Solution
{
public:
    int minAdjacentSwaps(vector<int> &nums, int a, int b)
    {
        int n = nums.size();
        int m = 1e9 + 7;

        int ct0 = 0, ct1 = 0, ct2 = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < a)
            {
                ans = (ans + ct1 + ct2) % m;
                ct0++;
            }
            else if (nums[i] >= a && nums[i] <= b)
            {
                ans = (ans + ct2) % m;
                ct1++;
            }
            else
            {
                ct2++;
            }
        }

        return ans;
    }
};