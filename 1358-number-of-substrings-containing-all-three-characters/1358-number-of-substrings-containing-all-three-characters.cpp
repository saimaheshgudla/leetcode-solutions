class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>hash(3,0);
        int l=0;
        int r=0;
        long long cnt=0;
        int n=s.size();
        while(r<n){
            hash[s[r]-'a']++;
            while(hash[0]>0&&hash[1]>0&&hash[2]>0){
                hash[s[l]-'a']--;
                l++;
            }
            cnt=cnt+(r-l+1);
            r++;
        }
        return  1LL*n*(n+1)/2 - cnt;;
    }
};