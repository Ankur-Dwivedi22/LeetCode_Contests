class Solution
{
public:
    bool prime[1001];
    void SieveOfEratosthenes(int n = 1000)
    {
        memset(prime, 1, sizeof(prime));
        prime[0] = 0;
        prime[1] = 0;
        for (int p = 2; p * p <= n; p++)
        {
            if (prime[p] == true)
            {
                for (int i = p * p; i <= n; i += p)
                {
                    prime[i] = false;
                }
            }
        }
    }

    int sumOfPrimesInRange(int n)
    {
        SieveOfEratosthenes();
        int r = 0, temp = n;
        while (temp > 0)
        {
            r = (r * 10) + (temp % 10);
            temp /= 10;
        }
        int lb = min(r, n);
        int ub = max(r, n);
        int ct = 0;
        for (int i = lb; i <= ub; i++)
        {
            if (prime[i])
            {
                ct += i;
            }
        }

        return ct;
    }
};