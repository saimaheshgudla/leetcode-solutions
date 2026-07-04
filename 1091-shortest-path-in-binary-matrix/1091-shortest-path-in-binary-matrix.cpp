class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        vector<vector<int>> vis(n,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},1});
        int dr[] = {-1,-1,-1,0,0,1,1,1};
        int dc[] = {-1,0,1,-1,1,-1,0,1};
        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int dist=q.front().second;
            q.pop();
            if(i==n-1 && j==n-1) return dist;
            for(int a=0;a<8;a++){
                int row=i+dr[a];
                int col=j+dc[a];
                if(row>=0 && row<n &&
                   col>=0 && col<n &&
                   grid[row][col]==0 &&
                   vis[row][col]==0){
                    vis[row][col] = 1;
                    q.push({{row,col},dist+1});
                }
            }
        }
        return -1;
    }
};