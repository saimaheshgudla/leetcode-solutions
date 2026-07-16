class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int m=times.size();
        for(int i=0;i<m;i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        vector<int> dis(n+1,1e9);
        dis[k]=0;
        dis[0]=0;
        pq.push({0,k});
        while(!pq.empty()){
            auto it=pq.top();
            int node=it.second;
            int dist=it.first;
            pq.pop();
            if(dist > dis[node]) continue;
            for(auto i:adj[node]){
                if(i.second+dist<dis[i.first]){
                    dis[i.first]=i.second+dist;
                    pq.push({dis[i.first],i.first});
                }
            }
        }
        int ans = *max_element(dis.begin() + 1, dis.end());
        if(ans == 1e9)
            return -1;
        return ans;
    }
};