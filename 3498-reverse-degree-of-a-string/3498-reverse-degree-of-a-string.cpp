class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        for(int i = 0; i < s.size(); i++){
            int value = 'z' - s[i] + 1;
            int product = (i + 1) * value;
            sum+= product;
        }
        return sum;
        
    }
};