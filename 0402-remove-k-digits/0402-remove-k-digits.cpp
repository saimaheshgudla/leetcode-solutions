class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;
        int cnt=k;
        for(int i=0;i<num.size();i++){
            while(!st.empty() && cnt>0 && st.back()>num[i]){
                st.pop_back();
                cnt--;
            }
            st.push_back(num[i]);
        }
        while(cnt>0){
            st.pop_back();
            cnt--;
        }
        int i=0;
        while(i < st.size() && st[i] == '0') i++;
        st = st.substr(i);
        if(st.empty()) return "0";
        return st;
    }
};