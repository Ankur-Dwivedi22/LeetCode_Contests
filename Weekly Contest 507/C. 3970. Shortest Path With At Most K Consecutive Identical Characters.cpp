class Solution
{
public:
    int shortestPath(int n, vector<vector<int>> &edges, string labels, int k)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (auto it : edges)
        {
            int u = it[0], v = it[1], w = it[2];
            adj[u].push_back({v, w});
        }

        vector<vector<int>> dist(n, vector<int>(k + 1, 1e9));
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
        pq.push({0, 0, 1});
        dist[0][1] = 0;

        while (!pq.empty())
        {
            auto it = pq.top();
            int sum = it[0], node = it[1], curr = it[2];
            pq.pop();

            if (sum > dist[node][curr])
                continue;
            if (node == n - 1)
                return sum;

            for (auto [adjNode, edW] : adj[node])
            {
                if (labels[adjNode] == labels[node])
                {
                    if (curr + 1 <= k && sum + edW < dist[adjNode][curr + 1])
                    {
                        dist[adjNode][curr + 1] = sum + edW;
                        pq.push({dist[adjNode][curr + 1], adjNode, curr + 1});
                    }
                }
                else
                {
                    if (sum + edW < dist[adjNode][1])
                    {
                        dist[adjNode][1] = sum + edW;
                        pq.push({dist[adjNode][1], adjNode, 1});
                    }
                }
            }
        }

        return -1;
    }
};