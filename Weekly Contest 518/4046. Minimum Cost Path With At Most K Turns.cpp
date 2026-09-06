// Dijkstra's Algorithm
// TC : O(M * N * K * log(M * N * K))
// SC : O(M * N * K)
class Solution {
public:
    using ll = long long;
    const ll INF = 1e18;
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<vector<ll>>>> dist(m, vector<vector<vector<ll>>>(n, vector<vector<ll>>(5, vector<ll>(k+1, INF))));
        priority_queue<vector<ll>, vector<vector<ll>>, greater<>> pq;
        // {cost, r, c, dir, turns}
        pq.push({grid[0][0], 0, 0, 4, 0});
        dist[0][0][4][0] = grid[0][0];

        vector<pair<ll, ll>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            ll cost = it[0], r = it[1], c = it[2], dir = it[3], turns = it[4];
            if(cost > dist[r][c][dir][turns]){
                continue;
            }

            if(r == m-1 && c == n-1){
                return cost;
            }

            for(int i=0; i<4; i++){
                ll nr = r + dirs[i].first;
                ll nc = c + dirs[i].second;

                if(nr < 0 || nr >= m || nc < 0 || nc >= n) continue;

                ll nturns = turns;
                if(dir != 4 && dir != i) nturns++;

                if(nturns > k) continue;
                ll ncost = grid[nr][nc] + cost;

                if(ncost < dist[nr][nc][i][nturns]){
                    dist[nr][nc][i][nturns] = ncost;
                    pq.push({ncost, nr, nc, i, nturns});
                }
            }            
        }

        return -1;
    }
};
