class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        for(int i=0;i<reservedSeats.size();i++){
            q.push({reservedSeats[i][0],reservedSeats[i][1]});
        }
        int prevrow=0;
        int cnt=0;
        while(!q.empty()){
            int row=q.top().first;
            if(row!=prevrow){
                cnt += (row - prevrow - 1) * 2;
                vector<int>seats;
                while(!q.empty() && q.top().first==row){
                    seats.push_back(q.top().second);
                    q.pop();
                }
                bool left=true;
                bool right=true;
                bool mid=true;
                for(auto seat:seats){
                    if(seat>=2 && seat<=5) left=false;
                    if(seat>=4 && seat<=7) mid=false;
                    if(seat>=6 && seat<=9) right=false;
                }
                if(left==true) cnt++;
                if(right==true) cnt++;
                if(left==false && right==false && mid==true) cnt++;
                prevrow=row;
            }
        }
        cnt += (n - prevrow) * 2;
        return cnt;
    }
};