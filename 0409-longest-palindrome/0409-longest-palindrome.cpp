class Solution {
public:
    int longestPalindrome(string s) {
        if(s.size()==1) return 1;
        unordered_map<char,int>mpp;
        for(char it:s){
            mpp[it]++;
        }
        int cnt=0;
        for(auto it:mpp){
            int vall=it.second/2;
            vall=vall*2;
            cnt=cnt+vall;
        }
        if(cnt==s.size()) return cnt;
        return cnt+1;
    }
};