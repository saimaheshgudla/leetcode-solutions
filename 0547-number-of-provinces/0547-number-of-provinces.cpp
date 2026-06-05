class Solution {
public:
    void dfs(int i,vector<int> adj[],vector<int> &vis){
        vis[i]=1;
        for(auto it:adj[i]){
            if(vis[it]!=1){
                dfs(it,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> adj[isConnected.size()];
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected.size();j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[j].push_back(i);
                    adj[i].push_back(j);
                }
            }
        }
        int cnt=0;
        vector<int>vis(isConnected.size(),0);
        for(int i=0;i<isConnected.size();i++){
            if(vis[i]!=1){
                cnt++;
                dfs(i,adj,vis);
            }
        }
        return cnt;
    }
};