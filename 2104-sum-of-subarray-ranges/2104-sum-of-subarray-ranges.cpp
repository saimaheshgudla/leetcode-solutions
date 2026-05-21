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
    vector<int> nle(vector<int>& arr) {
        stack<int> st;
        vector<int> res(arr.size(), 0);

        for(int i = arr.size() - 1; i >= 0; i--) {

            while(!st.empty() && arr[st.top()] <= arr[i]) {
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
    vector<int> ple(vector<int>& arr) {
        stack<int> st;
        vector<int> res(arr.size(), 0);

        for(int i = 0; i < arr.size(); i++) {

            while(!st.empty() && arr[st.top()] < arr[i]) {
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

    long long subArrayRanges(vector<int>& nums) {
        vector<int> Nse = nse(nums);
        vector<int> Pse = pse(nums);
        vector<int> Nle = nle(nums);
        vector<int> Ple = ple(nums);
        long long sum1 = 0;
        long long sum2 = 0;
        for(int i = 0; i < nums.size(); i++) {
            long long left1 = i - Pse[i];
            long long right1 = Nse[i] - i;
            long long left2 = i - Ple[i];
            long long right2 = Nle[i] - i;
            sum1=sum1+(right1)*left1*nums[i];
            sum2=sum2+right2*left2*nums[i];
        }
        return sum2-sum1;
    }
};