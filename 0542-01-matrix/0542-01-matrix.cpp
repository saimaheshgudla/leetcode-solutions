class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> res(mat.size(), vector<int>(mat[0].size(), -1));
        queue<pair<pair<int,int>,int>> q;

        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat[i].size(); j++) {
                if(mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    res[i][j] = 0;
                }
            }
        }

        while(!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int dis = q.front().second;
            q.pop();

            if(i - 1 >= 0 && res[i - 1][j] == -1) {
                res[i - 1][j] = dis + 1;
                q.push({{i - 1, j}, dis + 1});
            }

            if(j - 1 >= 0 && res[i][j - 1] == -1) {
                res[i][j - 1] = dis + 1;
                q.push({{i, j - 1}, dis + 1});
            }

            if(i + 1 < mat.size() && res[i + 1][j] == -1) {
                res[i + 1][j] = dis + 1;
                q.push({{i + 1, j}, dis + 1});
            }

            if(j + 1 < mat[i].size() && res[i][j + 1] == -1) {
                res[i][j + 1] = dis + 1;
                q.push({{i, j + 1}, dis + 1});
            }
        }

        return res;
    }
};