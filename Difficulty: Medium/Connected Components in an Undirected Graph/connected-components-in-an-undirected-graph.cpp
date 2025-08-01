
class Solution {
private:
    // Function for DFS traversal to collect a component
    void dfs(int node, vector<int> adj[], vector<int> &component, vector<int> &vis) {
        vis[node] = 1;
        component.push_back(node);

        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, component, vis);
            }
        }
    }

public:
    // Function to get all connected components in the graph
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];

        // Build the adjacency list
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // because it's an undirected graph
        }

        vector<vector<int>> components;

        // Perform DFS to find components
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                vector<int> component;
                dfs(i, adj, component, vis);
                components.push_back(component);
            }
        }

        return components;
    }
};
