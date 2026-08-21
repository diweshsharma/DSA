class Solution {
public:
    bool judgeSquareSum(int c) {
        // int n = sqrt(c);
        // vector<int> res;
        // for(int i = 0 ; i<=n; i++){
        //     res.push_back(i);
        // }
        long long i = 0; 
        long long j = sqrt(c);
        while(i <= j){
            long long num = i * i + j * j;
            if(c == num){
                return true;
            }
            else if(num < c){
                i++;
            }
            else{
                j--;
            }
        }return false;
    }
};