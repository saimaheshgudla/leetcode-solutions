class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;

        vector<vector<pair<int,int>>> adj(n);

        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }

        vector<vector<int>> dis(n, vector<int>(k+2, 1e9));

        dis[src][0] = 0;
        pq.push({0,{src,0}});

        while(!pq.empty()){

            auto it = pq.top();
            pq.pop();

            int dist = it.first;
            int node = it.second.first;
            int cnt = it.second.second;

            if(cnt > k+1) continue;

            for(auto i : adj[node]){

                int adjNode = i.first;
                int wt = i.second;

                if(cnt+1 <= k+1 && dist + wt < dis[adjNode][cnt+1]){

                    dis[adjNode][cnt+1] = dist + wt;
                    pq.push({dist+wt,{adjNode,cnt+1}});
                }
            }
        }

        int ans = 1e9;

        for(int i=0;i<=k+1;i++){
            ans = min(ans, dis[dst][i]);
        }

        if(ans == 1e9) return -1;
        return ans;
    }
};