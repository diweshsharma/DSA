class Solution {
public:
    int maxProduct(int n) {
        int first = 0;
        int second = 0;
        int digit = 0;
        while (n > 0) {
            digit = n % 10;
            n /= 10;
            if (first < digit) {
                second = first;
                first = digit;
            } else {if(digit > second){
                second = digit;}
            }
        }return first * second;
    }
};