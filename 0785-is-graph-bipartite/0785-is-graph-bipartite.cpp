class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> col(n, -1);

        for(int j = 0; j < n; j++) {
            if(col[j] != -1) continue;

            queue<int> q;
            q.push(j);
            col[j] = 0;

            while(!q.empty()) {
                int num = q.front();
                q.pop();

                for(int i : graph[num]) {
                    if(col[i] == -1) {
                        col[i] = !col[num];
                        q.push(i);
                    }
                    else if(col[i] == col[num]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};