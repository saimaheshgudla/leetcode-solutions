class Solution {
public:
    vector<int> nse(vector<int>& arr) {
        stack<int> st;
        vector<int> res(arr.size(), 0);

        for(int i = arr.size() - 1; i >= 0; i--) {

            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if(st.empty()) {
                res[i] = arr.size();   
            }
            else {
                res[i] = st.top();
            }

            st.push(i);
        }

        return res;
    }

    vector<int> pse(vector<int>& arr) {
        stack<int> st;
        vector<int> res(arr.size(), 0);

        for(int i = 0; i < arr.size(); i++) {

            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if(st.empty()) {
                res[i] = -1;
            }
            else {
                res[i] = st.top();
            }

            st.push(i);
        }

        return res;
    }

    int sumSubarrayMins(vector<int>& arr) {

        vector<int> Nse = nse(arr);
        vector<int> Pse = pse(arr);

        long long sum = 0;
        const int MOD = 1e9 + 7;

        for(int i = 0; i < arr.size(); i++) {

            long long left = i - Pse[i];
            long long right = Nse[i] - i;

            sum = (sum + (left * right % MOD) * arr[i]) % MOD;
        }

        return sum;
    }
};