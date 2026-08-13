class Solution {
public:
    int hammingWeight(int n) {
        int cnt=0;
        int a=n;
        while(a>0){
            cnt=cnt+(a%2);
            a=a/2;
        }
        return cnt;
    }
};