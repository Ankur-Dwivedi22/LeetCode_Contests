class Solution
{
public:
    vector<vector<int>> findDisappearedNumbers(vector<int> &nums, int lower, int upper)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        int s = lower;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > s)
            {
                if (nums[i] > upper)
                {
                    // ans.push_back({s, upper});
                    break;
                }
                else
                {
                    ans.push_back({s, nums[i] - 1});
                    s = nums[i] + 1;
                }
            }
            else if (nums[i] == s)
            {
                s++;
            }
            if (s > upper)
                break;
        }

        if (s <= upper)
        {
            ans.push_back({s, upper});
        }

        return ans;
    }
};