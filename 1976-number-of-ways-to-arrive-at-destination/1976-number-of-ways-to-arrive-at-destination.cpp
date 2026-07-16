class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        long long mod = 1e9 + 7;

        vector<vector<pair<int,int>>> adj(n);

        for(int i=0;i<roads.size();i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int wt = roads[i][2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        priority_queue<pair<long long,int>,
        vector<pair<long long,int>>,
        greater<pair<long long,int>>> pq;

        vector<long long> dis(n,LLONG_MAX);
        vector<long long> ways(n,0);

        dis[0] = 0;
        ways[0] = 1;

        pq.push({0,0});

        while(!pq.empty()){

            auto it = pq.top();
            pq.pop();

            long long dist = it.first;
            int node = it.second;

            if(dist > dis[node]) continue;

            for(auto i : adj[node]){

                int adjNode = i.first;
                int wt = i.second;

                if(dist + wt < dis[adjNode]){

                    dis[adjNode] = dist + wt;
                    ways[adjNode] = ways[node];

                    pq.push({dis[adjNode],adjNode});
                }

                else if(dist + wt == dis[adjNode]){

                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n-1] % mod;
    }
};