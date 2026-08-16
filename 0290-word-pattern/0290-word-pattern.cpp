class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string,int> mpps;
        unordered_map<char,int> mpppat;
        int n=pattern.size();
        int m=s.size();
        int j=0;
        int i=0;
        for(char it:pattern){
            if(j>=m) return false;
            string ans;
            while(j<m && s[j]!=' '){
                ans=ans+s[j];
                j++;
            }
            j++;
            if(mpppat[it]==0){
                if(mpps[ans]==0){
                    mpppat[it]=i+1;
                    mpps[ans]=i+1;
                }
                else return false;
            }
            if(mpppat[it]!=0){
                if(mpps[ans]==0)
                    return false;

                if(mpppat[it]!=mpps[ans])
                    return false;
            }
            i++;
        }
        if(j<m) return false;
        return true;
    }
};