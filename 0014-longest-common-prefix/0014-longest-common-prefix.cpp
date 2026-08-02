class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1){
            return strs[0];
        }
        int cnt=0;
        int j=0;
        string b="";
        while(j<strs[0].size()){
            string a(1, strs[0][j]);
            int cnt=0;
            for(int i=0;i<strs.size();i++){
                string c(1, strs[i][j]);
                if(c==a){
                    cnt++;
                }
                else break;
            }
            if(cnt<strs.size()) break;
            else {
                b=b+a;
                j++;
            }
        }
        return b;
    }
};