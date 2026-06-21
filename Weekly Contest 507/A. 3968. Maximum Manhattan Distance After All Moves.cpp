class Solution
{
public:
    int maxDistance(string moves)
    {
        int x = 0, y = 0, ct = 0;
        for (char c : moves)
        {
            if (c == 'U')
                x++;
            else if (c == 'D')
                x--;
            else if (c == 'R')
                y++;
            else if (c == 'L')
                y--;
            else
                ct++;
        }

        return abs(x) + abs(y) + ct;
    }
};