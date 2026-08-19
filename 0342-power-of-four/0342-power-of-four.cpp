class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false; 
        int a=n;
        while(a>1){
            if(a%4!=0) return false;
            a=a/4;
        }
        if(a==1) return true;
        return true;
    }
};