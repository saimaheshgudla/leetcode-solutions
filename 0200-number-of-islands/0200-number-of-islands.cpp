class Solution {
public:
    void bfs(int i,int j,vector<vector<int>> &vis,vector<vector<char>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        vis[i][j]=1;
        queue<pair<int,int>> q;
        q.push({i,j});
        vector<int> rows={-1,1,0,0};
        vector<int> cols={0,0,-1,1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int a=0;a<4;a++){
                int crow=rows[a]+row;
                int ccol=cols[a]+col;
                if(ccol>=0 && crow>=0 && ccol<m && crow<n && vis[crow][ccol]==0 && grid[crow][ccol]=='1'){
                    vis[crow][ccol]=1;
                    q.push({crow,ccol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    bfs(i,j,vis,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};