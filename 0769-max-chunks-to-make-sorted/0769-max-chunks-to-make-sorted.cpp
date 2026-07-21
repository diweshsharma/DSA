class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chunk = 0;
        int maxof = INT_MIN;
        for (int i = 0; i < arr.size(); i++){
            maxof = max(maxof , arr[i]);
            if(maxof == i){
                chunk++;
            }
        }return chunk;
    }
};