class Solution
{
public:
    bool canReach(vector<int> &start, vector<int> &target)
    {
        int s = abs(start[0] - target[0]) + abs(start[1] - target[1]);
        return s % 2 == 0;
    }
};