class Solution {
public:
    bool checkDivisibility(int n) {
        long long prod=1;
        long long sum=0;
        int a=n;
        while(a>0){
            int val=a%10;
            if(a>0){
                prod=prod*val;
            }
            sum=sum+val;
            a=a/10;
        }
        return n%(sum+prod)==0;
    }
};