#include <vector>

class Solution {
private:
    void dfs(int u, const std::vector<std::vector<int>>& adj, std::vector<bool>& suspicious) {
        suspicious[u] = true;
        for (int v : adj[u]) {
            if (!suspicious[v]) {
                dfs(v, adj, suspicious);
            }
        }
    }

public:
    std::vector<int> remainingMethods(int n, int k, std::vector<std::vector<int>>& invocations) {
        // Build directed adjacency list
        std::vector<std::vector<int>> adj(n);
        for (const auto& edge : invocations) {
            adj[edge[0]].push_back(edge[1]);
        }

        // Phase 1: Mark all methods reachable from 'k' as suspicious
        std::vector<bool> suspicious(n, false);
        dfs(k, adj, suspicious);

        // Phase 2: Check if any unsuspicious method calls a suspicious one
        for (const auto& edge : invocations) {
            if (!suspicious[edge[0]] && suspicious[edge[1]]) {
                std::vector<int> all_methods(n);
                for (int i = 0; i < n; ++i) all_methods[i] = i;
                return all_methods; // Retain all methods
            }
        }

        // Phase 3: Filter out suspicious methods
        std::vector<int> remaining;
        remaining.reserve(n);
        for (int i = 0; i < n; ++i) {
            if (!suspicious[i]) {
                remaining.push_back(i);
            }
        }
        return remaining;
    }
};