class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || j==0 || i==n-1 || j==m-1) && grid[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        vector<int> row={-1,1,0,0};
        vector<int> col={0,0,1,-1};
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int coll=j+col[k];
                int roww=i+row[k];
                if(coll>=0 && roww>=0 && coll<m && roww<n && grid[roww][coll]==1 && vis[roww][coll]==0){
                    q.push({roww,coll});
                    vis[roww][coll]=1;
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};