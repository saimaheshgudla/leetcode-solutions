class Solution {
public:
    int cnt(int n,int m,int i,int j,vector<vector<int>>& vis){
        if(i==0 && j==0) return 1;
        if (i < 0 || j < 0) return 0;
        if(vis[i][j]!=-1) return vis[i][j];
        int right=cnt(n,m,i,j-1,vis);
        int down=cnt(n,m,i-1,j,vis);
        return vis[i][j]=right+down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> vis(m,vector<int>(n,-1));
        return cnt(n,m,m-1,n-1,vis);
    }
};