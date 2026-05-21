class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int i=0;i<asteroids.size();i++){
            while(!st.empty() && st.top()>0 && asteroids[i]<0){
                int num=-1*asteroids[i];
                if(num>st.top()) st.pop();
                else break;
            }
            if(!st.empty() && st.top()>0 && asteroids[i]<0){
                if(asteroids[i] + st.top() == 0){
                    st.pop();
                }
            }
            
            else{
                st.push(asteroids[i]);
            }
        }
        vector<int>res(st.size(),0);
        for(int i=st.size()-1;i>=0;i--){
            res[i]=st.top();
            st.pop();
        }
        return res;
    }
};