class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> rev(n);
        vector<int> indg(n,0);
        for(int i=0;i<graph.size();i++){
            for(auto it:graph[i]){
                rev[it].push_back(i);
                indg[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indg[i]==0){
                q.push(i);
            }
        }
        vector<int> safnode;
        while(!q.empty()){
            int val=q.front();
            q.pop();
            safnode.push_back(val);
            for(int i=0;i<rev[val].size();i++){
                int node = rev[val][i];
                indg[node]--;
                if(indg[node]==0){
                    q.push(node);
                }
            }
        }
        sort(safnode.begin(), safnode.end());
        return safnode;
    }
};