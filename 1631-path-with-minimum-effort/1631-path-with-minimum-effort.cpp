class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int n=heights.size();
        int m = heights[0].size(); 
        vector<vector<int>> dis(n,vector<int>(m,1e9));
        pq.push({0,{0,0}});
        dis[0][0]=0;
        vector<int>dc={-1,1,0,0};
        vector<int>dr={0,0,-1,1};
        while(!pq.empty()){
            auto it=pq.top();
            int diff=it.first;
            int k=it.second.first;
            int j=it.second.second;
            if(k==n-1&&j==m-1) return dis[k][j];
            pq.pop();
            for(int i=0;i<4;i++){
                int row=k+dr[i];
                int col=j+dc[i];
                if(row >=0 && col>=0 && col<m && row<n){
                    int dif=abs(heights[k][j]-heights[row][col]);
                    int neweff=max(dif,diff);
                    if(neweff<dis[row][col]){
                        dis[row][col]=neweff;
                        pq.push({dis[row][col],{row,col}});
                    }
                }
            }
        }
        return 0;
    }
};