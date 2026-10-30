class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].emplace_back(edge[1], edge[2]);
        }
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        const int INF = 1e9;
        vector<vector<int>> minDist(n, vector<int>(k + 1, INF));
        int startCon = 1;
        pq.push({0, 0, startCon});
        minDist[0][startCon] = 0;

        while (!pq.empty()) {
            auto [dist, u, consec] = pq.top();
            pq.pop();

            if (u == n - 1) {
                return dist;
            }

            if (dist > minDist[u][consec]) {
                continue;
            }

            for (const auto& [v, weight] : adj[u]) {
                char charU = labels[u];
                char charV = labels[v];

                int nextCon = (charU == charV) ? consec + 1 : 1;
                if (nextCon > k) {
                    continue;
                }

                if (dist + weight < minDist[v][nextCon]) {
                    minDist[v][nextCon] = dist + weight;
                    pq.push({minDist[v][nextCon], v, nextCon});
                }
            }
        }

        int ans = INF;
        for (int c = 1; c <= k; ++c) {
            ans = min(ans, minDist[n - 1][c]);
        }

        return ans == INF ? -1 : ans; 
    }
};