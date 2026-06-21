class Solution
{
public:
    long long dfs(int node, int par, vector<int> &tm, vector<vector<int>> &adj)
    {
        long long ans = 0;
        if (adj[node].empty())
        {
            return tm[node];
        }

        long long mn = -1, mx = -1;
        for (int adjNode : adj[node])
        {
            if (adjNode != par)
            {
                long long val = dfs(adjNode, node, tm, adj);
                if (mn == -1 || val < mn)
                    mn = val;
                if (mx == -1 || val > mx)
                    mx = val;
            }
        }

        ans = mx + (mx - mn) + tm[node];
        return ans;
    }
    long long finishTime(int n, vector<vector<int>> &edges, vector<int> &baseTime)
    {
        vector<vector<int>> adj(n);

        for (auto it : edges)
        {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
        }

        return dfs(0, -1, baseTime, adj);
    }
};