class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;
        int val=image[sr][sc];
        image[sr][sc]=color;
        q.push({sr,sc});
        vector<vector<int>> vis(image.size(),vector<int>(image[0].size(),0));
        vis[sr][sc]=1;
        while(!q.empty()){
            int sr=q.front().first;
            int sc=q.front().second;
            q.pop();
            if(sr-1>=0 && vis[sr-1][sc]!=1 && image[sr-1][sc]==val){
                vis[sr-1][sc]=1;
                q.push({sr-1,sc});
                image[sr-1][sc]=color;
            }
            if(sr+1<image.size() && vis[sr+1][sc]!=1 && image[sr+1][sc]==val){
                vis[sr+1][sc]=1;
                q.push({sr+1,sc});
                image[sr+1][sc]=color;
            }
            if(sc-1>=0 && vis[sr][sc-1]!=1 && image[sr][sc-1]==val){
                vis[sr][sc-1]=1;
                q.push({sr,sc-1});
                image[sr][sc-1]=color;
            }
            if(sc+1<image[sr].size() && vis[sr][sc+1]!=1 && image[sr][sc+1]==val){
                vis[sr][sc+1]=1;
                q.push({sr,sc+1});
                image[sr][sc+1]=color;
            }
        }
        return image;  
    }
};