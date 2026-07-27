class Solution
{
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>> &s1, vector<vector<int>> &s2)
    {
        vector<vector<int>> ans;
        int n1 = s1.size(), n2 = s2.size();
        int i = 0, j = 0;
        while (i < n1 && j < n2)
        {
            int val;
            if (s1[i][0] == s2[j][0])
            {
                val = s1[i][1] + s2[j][1];
                ans.push_back({s1[i][0], val});
                i++;
                j++;
            }
            else if (s1[i][0] < s2[j][0])
            {
                val = s1[i][1] + s2[j][1];
                ans.push_back({s1[i][0], val});
                i++;
            }
            else
            {
                val = s1[i][1] + s2[j][1];
                ans.push_back({s2[j][0], val});
                j++;
            }
        }

        while (i < n1)
        {
            ans.push_back(s1[i]);
            i++;
        }

        while (j < n2)
        {
            ans.push_back(s2[j]);
            j++;
        }

        return ans;
    }
};