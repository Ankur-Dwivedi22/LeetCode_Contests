class Solution
{
public:
    int largestInteger(int n, int s)
    {
        int num = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int d = 9; d >= 0; d--)
            {
                if (s >= d)
                {
                    s -= d;
                    num = (num * 10) + d;
                    break;
                }
            }
        }

        return (s == 0 ? num : -1);
    }
};