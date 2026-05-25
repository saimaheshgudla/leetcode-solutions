class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int total=0;
        int n=cardPoints.size();
        for(int i=0;i<n;i++){
            total=total+cardPoints[i];
        }
        int l=0;
        int r=n-k-1;
        int minsum=0;
        for(int i=0;i<=r;i++){
            minsum=minsum+cardPoints[i];
        }
        int sum=minsum;
        while(r<n-1){
            minsum=minsum-cardPoints[l];
            l++;
            r++;
            minsum=minsum+cardPoints[r];
            sum=min(sum,minsum);
        }
        return total-sum;
    }   
};