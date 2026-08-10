class Solution {
public:
    int mySqrt(int x) {
        int i=1;
        int j=x;
        while(i<=j){
            long long mid=i+(j-i)/2;
            if(mid*mid >x){
                j=mid-1;
            }
            else if(mid*mid <x){
                i=mid+1;
            }
            else {
                return mid;
            }
        }
        return j;
    }
};