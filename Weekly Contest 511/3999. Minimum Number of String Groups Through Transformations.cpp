class Solution
{
public:
    string getMinStr(string s)
    {
        int n = s.size();
        s += s;

        int i = 0, j = 1, k = 0;
        while (i < n && j < n && k < n)
        {
            if (s[i + k] == s[j + k])
            {
                k++;
            }
            else if (s[i + k] > s[j + k])
            {
                i += k + 1;
                if (i <= j)
                    i = j + 1;
                k = 0;
            }
            else
            {
                j += k + 1;
                if (j <= i)
                    j = i + 1;
                k = 0;
            }
        }

        int mnIdx = min(i, j);
        return s.substr(mnIdx, n);
    }

    int minimumGroups(vector<string> &words)
    {
        unordered_set<string> st;

        for (string word : words)
        {
            string even = "", odd = "";
            for (int i = 0; i < word.size(); i++)
            {
                if (i % 2 == 0)
                    even += word[i];
                else
                    odd += word[i];
            }

            string h = getMinStr(even) + "*" + getMinStr(odd);
            st.insert(h);
        }

        return st.size();
    }
};