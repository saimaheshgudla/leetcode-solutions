class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        queue<int> q;
        q.push(connections[0][0]);
        vector<int> vis(n,0);
        vector<int>cnt(n,0);
        for(int start=0;start<n;start++){
            if(vis[start]==1) continue;
            queue<int>q;
            q.push(start);
            while(!q.empty()){
                int node=q.front();
                q.pop();
                if(vis[node]==1) continue;
                vis[node]=1;
                for(auto it:adj[node]){
                    if(vis[it]!=1){
                        cnt[it]++;
                        q.push(it);
                    }
                }
            }
        }
        
        int noncnt=0;
        int extra=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0) noncnt++;
            if(cnt[i]>1){
                extra+=(cnt[i]-1);
            }
        }

        if((int)connections.size() < n-1) return -1;  
        int totalEdges = connections.size();
        int c = n - totalEdges + extra;  
        return c - 1;
    }
};