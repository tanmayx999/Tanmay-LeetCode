class Solution {
public:
    int smallestNumber(int n, int t) {
        int num = n;
        while (true) {
            int prod = 1;
            int temp = num;
            
            // Extract and multiply digits
            while (temp > 0) {
                prod *= temp % 10;
                temp /= 10;
            }
            
            // Check if product is divisible by t
            if (prod % t == 0) {
                return num;
            }
            num++;
        }
    }
};