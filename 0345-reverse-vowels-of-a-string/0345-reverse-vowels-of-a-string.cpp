class Solution {
public:
    bool tovowel(char c){
        c=tolower(c);
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }
    string reverseVowels(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<j){
            char si=s[i];
            char sj=s[j];
            while(i<j && !tovowel(s[i])) i++;
            while(j>i && !tovowel(s[j])) j--;
            swap(s[i],s[j]);
            i++;
            j--;
        }
        return s;
    }
};