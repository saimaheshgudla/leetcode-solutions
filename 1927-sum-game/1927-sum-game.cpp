class Solution {
public:
    bool sumGame(string num) {
        int first=0;
        int last=0;
        int q1=0;
        int q2=0;
        int n=num.size();
        for(int i=0;i<num.size();i++){
            if(i<(n/2)){
                if(num[i]=='?') q1++;
                else first=first+(num[i]-'0');
            }
            else {
                if(num[i]=='?') q2++;
                else last=last+(num[i]-'0');
            }
        }
        if((q1+q2)%2==1) return true;
        int diff=first-last;
        if(q1==q2){
            return diff!=0;
        }
        if(q1>q2){
            diff=diff+((q1-q2)/2)*9;
        }
        else{
            diff=diff-((q2-q1)/2)*9;
        }
        return diff!=0;
    }
};