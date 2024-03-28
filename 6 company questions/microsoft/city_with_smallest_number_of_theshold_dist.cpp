class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
       unordered_map<int, vector<pair<int, int>>> adj;
    for(auto& edge : edges) {
        adj[edge[0]].push_back({edge[1], edge[2]});
        adj[edge[1]].push_back({edge[0], edge[2]});
    }

    int ans = -1;
    int minReachable = INT_MAX;

    for(int i = 0; i < n; i++) {
        vector<int> dist(n, INT_MAX);
        dist[i] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // Min-heap based on distance
        pq.push({0, i}); // Distance to self is 0

        while(!pq.empty()) {
            int d = pq.top().first, node = pq.top().second;
            pq.pop();

            if(d > dist[node]) continue;

            for(auto& it : adj[node]) {
                int nextNode = it.first, weight = it.second;
                if(dist[node] + weight < dist[nextNode] && dist[node] + weight <= distanceThreshold) {
                    dist[nextNode] = dist[node] + weight;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        int reachable = count_if(dist.begin(), dist.end(), [&distanceThreshold](int d) { return d <= distanceThreshold; });
        
        if(reachable <= minReachable) {
            minReachable = reachable;
            ans = i; // Prefer the city with the higher ID in case of a tie
        }
    }

    return ans;
    }
};