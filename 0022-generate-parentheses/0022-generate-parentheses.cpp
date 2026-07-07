class Solution {
private:
void generate(int open , int close , int n , string &temp  , vector<string> &res){
    if(open == n && close == n){
        res.push_back(temp);
        return;
    }

    if(open < n){
        temp.push_back('(');
        generate(open + 1, close , n , temp , res);
        temp.pop_back();
    }

    if(close < open){
        temp.push_back(')');
        generate(open , close + 1 , n , temp , res);
        temp.pop_back();
    }
}
public:
    vector<string> generateParenthesis(int n) {
        int open = 0 , close = 0;
        string temp = "";
        vector<string> res;
        generate(open , close , n , temp , res);
        return res;
    }
};