class Solution
{
public:
    vector<bool> transformStr(string s, vector<string> &strs)
    {
        vector<bool> ans;
        int ct0 = 0, ct1 = 0;
        int n = s.size();
        vector<int> pre;
        for (char c : s)
        {
            if (c == '0')
                ct0++;
            else
                ct1++;
            pre.push_back(ct0);
        }

        for (string str : strs)
        {
            int c0 = 0, c1 = 0, ct = 0;
            for (char c : str)
            {
                if (c == '0')
                    c0++;
                else if (c == '1')
                    c1++;
                else
                    ct++;
            }
            int q0 = max(0, ct0 - c0);
            int q1 = max(0, ct1 - c1);
            if (c0 > ct0 || c1 > ct1)
            {
                ans.push_back(false);
            }
            else
            {
                int fl = 1;
                int curr0 = 0;
                for (int i = 0; i < n; i++)
                {
                    char c = str[i];

                    if (c == '?')
                    {
                        if (q0 > 0)
                        {
                            c = '0';
                            q0--;
                        }
                        else
                        {
                            c = '1';
                        }
                    }

                    if (c == '0')
                        curr0++;
                    if (curr0 < pre[i])
                    {
                        fl = 0;
                        break;
                    }
                }

                if (fl)
                    ans.push_back(true);
                else
                    ans.push_back(false);
            }
        }
        return ans;
    }
};