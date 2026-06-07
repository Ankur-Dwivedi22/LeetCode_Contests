// Approach : Greedy
// TC : O(logn)
// SC : O(1)
class Solution
{
public:
    bool consecutiveSetBits(int n)
    {
        int prev = 0, ct = 0;
        while (n > 0)
        {
            int dig = n % 2;
            n /= 2;
            if (dig == 1 && prev == 1)
            {
                ct++;
            }
            prev = dig;
        }

        return (ct == 1);
    }
};