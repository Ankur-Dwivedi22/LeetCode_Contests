class Solution
{
public:
    using ll = long long;
    long long minCost(int m, int n, vector<vector<int>> &penalty)
    {
        vector<vector<vector<ll>>> dist(m, vector<vector<ll>>(n, vector<ll>(2, 1e18)));
        priority_queue<vector<ll>, vector<vector<ll>>, greater<>> pq;

        dist[0][0][1] = 1;
        pq.push({1, 0, 0, 1});

        vector<int> dr = {0, +1, 0, -1};
        vector<int> dc = {+1, 0, -1, 0};

        while (!pq.empty())
        {
            auto it = pq.top();
            ll d = it[0], r = it[1], c = it[2], p = it[3];
            pq.pop();
            if (r == m - 1 && c == n - 1)
                return d;
            if (d > dist[r][c][p])
                continue;

            ll nd = d + penalty[r][c];
            if (nd < dist[r][c][!p])
            {
                dist[r][c][!p] = nd;
                pq.push({nd, r, c, !p});
            }

            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;
                ll e = 0;
                if (p == 1 && (i == 2 || i == 3))
                {
                    e = penalty[r][c];
                }
                else if (p == 0 && (i == 0 || i == 1))
                {
                    e = penalty[r][c];
                }

                nd = d + e + (nr + 1) * 1ll * (nc + 1);
                if (nd < dist[nr][nc][!p])
                {
                    dist[nr][nc][!p] = nd;
                    pq.push({nd, nr, nc, !p});
                }
            }
        }

        return -1;
    }
};