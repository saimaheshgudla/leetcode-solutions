class Solution {
public:
    int smallestNumber(int n, int t) {
        int cnt = n;

        while (true) {
            int num = cnt;
            int prod = 1;

            if (num == 0) {
                prod = 0;
            } else {
                while (num > 0) {
                    prod *= (num % 10);
                    num /= 10;
                }
            }

            if (prod % t == 0)
                return cnt;

            cnt++;
        }
    }
};