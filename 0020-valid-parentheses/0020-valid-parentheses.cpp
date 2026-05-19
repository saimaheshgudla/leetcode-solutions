class Solution {
public:
    bool isValid(string s) {

        if(s.size() % 2 != 0){
            return false;
        }

        stack<char> s1;
        stack<char> s2;

        for(int i = 0; i < s.size(); i++){
            s1.push(s[i]);
        }

        while(!s1.empty()) {

            if(s2.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            else {

                char val1 = s1.top();
                char val2 = s2.top();

                // ✅ use diff instead of conversion + comparison
                int diff = val2 - val1;

                if(diff == 1 || diff == 2){
                    s1.pop();
                    s2.pop();
                }
                else {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
        }

        return s2.empty();
    }
};