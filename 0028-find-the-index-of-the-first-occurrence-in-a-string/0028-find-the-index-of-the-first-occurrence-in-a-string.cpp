class Solution {
public:
    int check( string s1,string s2){
        int i=0;
        int n=s1.size();
        int m=s2.size();
        int j=0;
        int prev=-1;
        while(j<n){
            if(s1[j]==s2[i]){
                if(i==0) prev=j;
                i++;
                if(i==m) return prev;
                j++;
            }
            else{
                if(i>0) {
                    i=0;
                    j=prev+1;
                }
                else j++;
            }
        }
        return -1;
    }
    int strStr(string haystack, string needle) {
        return check(haystack,needle);
    }
};