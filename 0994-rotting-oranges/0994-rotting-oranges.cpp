class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                } 
            }
        }
        
        int a=0;
        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int time=q.front().second;
            q.pop();
            a=max(a,time);
            if(i-1>=0 && vis[i-1][j]!=1 && grid[i-1][j]==1){
                q.push({{i-1,j},time+1});
                vis[i-1][j]=1;
            }
            if(i+1<grid.size() && vis[i+1][j]!=1 && grid[i+1][j]==1){
                q.push({{i+1,j},time+1});
                vis[i+1][j]=1;
            }
            if(j-1>=0 && vis[i][j-1]!=1 && grid[i][j-1]==1){
                q.push({{i,j-1},time+1});
                vis[i][j-1]=1;
            }
            if(j+1<grid[0].size() && vis[i][j+1]!=1 && grid[i][j+1]==1){
                q.push({{i,j+1},time+1});
                vis[i][j+1]=1;
            }
        }
        for(int i=0;i<vis.size();i++){
            for(int j=0;j<vis[i].size();j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    return -1;
                }
            }
        }
        return a;
    }
};