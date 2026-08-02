class Solution {
public:
    int minnum(int i,int j,vector<vector<int>>& vis,vector<vector<int>>& grid){
        if(i==0 && j==0) return grid[i][j];
        if(i<0||j<0) return 1e9;
        if(vis[i][j]!=-1) return vis[i][j];
        int left=grid[i][j]+minnum(i-1,j,vis,grid);
        int down=grid[i][j]+minnum(i,j-1,vis,grid);
        return vis[i][j]=min(left,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,-1));
        return minnum(m-1,n-1,vis,grid);
    }
};