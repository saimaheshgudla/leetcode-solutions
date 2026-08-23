class Solution {
public:
    int countSegments(string s) {
        int cnt=0;
        int i=0;
        while(i<s.size()&&s[i]==' '){
            i++;
        }
        while(i<s.size()){
            if(s[i]==' ' && i>0){
                cnt++;
                while(i<s.size()&& s[i]==' '){
                    i++;
                }
            }
            else{
                i++;
            }
        }
        if(i > 0 && s[i-1] != ' ')
            cnt++;
        return cnt;
    }
};