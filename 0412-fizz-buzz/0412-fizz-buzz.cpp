class Solution {
public:
    vector<string> fizzBuzz(int n) {
        string f="Fizz";
        string b="Buzz";
        string fb="FizzBuzz";
        vector<string> ans;
        for(int i=0;i<n;i++){
            int val=i+1;
            if(val%3==0 && val%5==0){
                ans.push_back(fb);
            }
            else if(val%3==0){
                ans.push_back(f);
            }
            else if(val%5==0){
                ans.push_back(b);
            }
            else{
                ans.push_back(to_string(i+1));
            }
        }
        return ans;
    }
};