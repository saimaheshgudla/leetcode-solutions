class Solution {
public:
    int cnt(int i,int j,vector<vector<int>>& vis,vector<vector<int>>& obstacleGrid){
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        if(i<0||j<0) return 0;
        if(obstacleGrid[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
        if(vis[i][j]!=-1) return vis[i][j];
        int right=cnt(i,j-1,vis,obstacleGrid);
        int down=cnt(i-1,j,vis,obstacleGrid);
        return vis[i][j]=right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,-1));
        return cnt(n-1,m-1,vis,obstacleGrid);
    }
};