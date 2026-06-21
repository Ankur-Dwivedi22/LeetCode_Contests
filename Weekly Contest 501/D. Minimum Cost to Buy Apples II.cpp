// Approach : Dijkstra's Algorithm
// TC : O(E) + O (N * (E * logN + N))
// SC : O(N) + O(N) + O(N * N)


class Solution {
public:
    using ll = long long;
    vector<ll> fun(int n, int s, vector<vector<pair<ll, ll>>>& adj) {
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<>> pq;
        vector<ll> dist(n, 1e18);
        pq.push({0, s});
        dist[s] = 0;
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            ll node = it.second;
            ll dis = it.first;

            if(dis > dist[node]) continue;

            for (auto it : adj[node]) {
                ll adjNode = it.first;
                ll edgW = it.second;

                if (dis + edgW < dist[adjNode]) {
                    dist[adjNode] = dis + edgW;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
    
    vector<int> minCost(int n, vector<int>& prices,
                        vector<vector<int>>& roads) {
        vector<vector<pair<ll, ll>>> adj1(n), adj2(n);
        for (auto it : roads) {
            int u = it[0], v = it[1], c = it[2], t = it[3];
            adj1[u].push_back({v, c});
            adj1[v].push_back({u, c});
            adj2[u].push_back({v, c * 1ll * t});
            adj2[v].push_back({u, c * 1ll * t});
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            vector<ll> dist1 = fun(n, i, adj1);
            vector<ll> dist2 = fun(n, i, adj2);
            ll c = prices[i];
            for (int j = 0; j < n; j++) {
                if (j == i)
                    continue;
                ll c2 = dist1[j] + prices[j] + dist2[j];
                c = min(c, c2);
            }
            ans.push_back((int)c);
        }

        return ans;
    }
};