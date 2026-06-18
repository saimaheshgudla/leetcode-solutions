class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> vis(mat.size(),vector<int>(mat[0].size(),0));
        vector<vector<int>> res(mat.size(),vector<int>(mat[0].size(),0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        
        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int dis=q.front().second;
            q.pop();
            res[i][j]=dis;
            if(i-1>=0 && vis[i-1][j]==0 ){
                vis[i-1][j]=1;
                q.push({{i-1,j},dis+1});
            }
            if(j-1>=0 && vis[i][j-1]==0 ){
                vis[i][j-1]=1;
                q.push({{i,j-1},dis+1});
            }
            if(i+1<mat.size() && vis[i+1][j]==0 ){
                vis[i+1][j]=1;
                q.push({{i+1,j},dis+1});
            }
            if(j+1<mat[i].size() && vis[i][j+1]==0 ){
                vis[i][j+1]=1;
                q.push({{i,j+1},dis+1});
            }
        }
        return res;
    }
};