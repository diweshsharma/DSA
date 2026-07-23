class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>> group;
        for(int i = 0; i< strs.size(); i++){
            string word = strs[i];
            sort(word.begin() , word.end());
            group[word].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto val : group){
            ans.push_back(val.second);
        }
        return ans;

    }
};