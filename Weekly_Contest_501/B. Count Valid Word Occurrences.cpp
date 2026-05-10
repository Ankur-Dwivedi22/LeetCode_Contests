// Approach : Simulation and map
// TC : O(N + Q)
// SC : O(N)
class Solution
{
public:
    vector<int> countWordOccurrences(vector<string> &chunks, vector<string> &queries)
    {
        string s = "";
        for (auto it : chunks)
        {
            s += it;
        }

        string sub = "";
        unordered_map<string, int> mp;
        int n = s.size();
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                sub += s[i];
            }
            else if (s[i] == '-')
            {
                if (i - 1 >= 0 && i + 1 < n)
                {
                    if ((s[i - 1] != '-' && s[i - 1] != ' ') && (s[i + 1] != '-' && s[i + 1] != ' '))
                    {
                        sub += s[i];
                    }
                    else
                    {
                        if (!sub.empty())
                        {
                            mp[sub]++;
                        }
                        sub = "";
                    }
                }
            }
            else
            {
                mp[sub]++;
                sub = "";
            }
        }

        if (!sub.empty())
        {
            mp[sub]++;
        }

        vector<int> ans;
        for (string it : queries)
        {
            ans.push_back(mp[it]);
        }

        return ans;
    }
};