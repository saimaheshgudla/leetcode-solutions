class Solution {
public:
    int int_to_bit(int i){
        if(i==0) return 0;
        if(i==1) return 1;
        int val=0;
        if(i%2==0) val=int_to_bit(i/2);
        else val=1+int_to_bit(i/2);
        return val;
    }
    vector<int> countBits(int n) {
        vector<int>ans(n+1);
        for(int i=0;i<=n;i++){
            int val=int_to_bit(i);
            ans[i]=val;
        }
        return ans;
    }
};