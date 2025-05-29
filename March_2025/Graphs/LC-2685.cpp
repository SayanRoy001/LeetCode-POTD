class Solution {
    private:
        void bfs(int start, vector<int>& visited, vector<vector<int>>& adj,
                    int &countN,int &countE ) {
            queue<int> q;
            q.push(start);
            visited[start] = 1;
            while (!q.empty()) {
                int node = q.front();
                countN++;
                q.pop();
                for (auto it : adj[node]) {
                                        countE++;
                    if (visited[it] == 0) {
    
                        q.push(it);
                        visited[it] = 1;
                    }
                }
            }
        }
    public:
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            vector<vector<int>> adj(n);
            for (auto it : edges) {
                adj[it[0]].push_back(it[1]);
                adj[it[1]].push_back(it[0]);
            }
            int ans = 0;
            vector<int> visited(n, 0);
            for (int i = 0; i < n; i++) {
                
                if (visited[i] == 0) {
                    int countN=0;int countE=0;
                    bfs(i, visited, adj,countN,countE);
                     if (countE/2 == (countN * (countN-1) / 2)) {
                    ans++;
                }
                }
               
            }
            return ans;
        }
    };