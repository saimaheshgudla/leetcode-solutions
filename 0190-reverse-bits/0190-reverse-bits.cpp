class Solution {
public:
    int reverseBits(int n) {
        long long ans=0;
        int i=0;
        int a=n;
        while(a>0){
            int rem=a%2;
            ans=ans+(rem*pow(2,31-i));
            a=a/2;
            i++;
        }
        return ans;
    }
};