class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int i=n-1;
        int cnt=0;
        while(i>=0){
            if(isalnum(s[i])) cnt++;
            if(s[i]==' ' && cnt>0) return cnt;
            i--;
        }
        return cnt;
    }
};