#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(int src, vector<vector<int>>& adj, vector<int>& dist) {
        dist[src] = 0;
        queue<int> q;
        q.push(src);
        while (!q.empty()) {
           int node = q.front();
            q.pop();
            for (auto adjNode : adj[node]) {
                if (dist[node] + 1 < dist[adjNode]) {
                    dist[adjNode] = dist[node] + 1;
                    q.push(adjNode);
                }
            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            if (edges[i] != -1) {
                adj[i].push_back(edges[i]);
            }
        }
        vector<int> dist1(n, INT_MAX);
        vector<int> dist2(n, INT_MAX);
        bfs(node1, adj, dist1);
        bfs(node2, adj, dist2);
        int ans = -1;
        int best = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (dist1[i] == INT_MAX || dist2[i] == INT_MAX)
                continue;
            int d = max(dist1[i], dist2[i]);
            if (d < best) {
                best = d;
                ans = i;
            }
        }
        return ans;
    }
};

// Wrapper function (preserves Solution class unchanged)
int findClosestMeetingNode(vector<int>& edges, int node1, int node2) {
    Solution sol;
    return sol.closestMeetingNode(edges, node1, node2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;                 // number of nodes
    vector<int> edges(n);
    for (int i = 0; i < n; i++) {
        cin >> edges[i];
    }
    int node1, node2;
    cin >> node1 >> node2;

    int result = findClosestMeetingNode(edges, node1, node2);
    cout << result << "\n";
    return 0;
}
