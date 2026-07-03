class Solution {
public:
    struct cmp{
    bool operator()(pair<int,char>&a,pair<int,char>&b){
        if(a.first!=b.first){
            return a.first<b.first;
        }
        else{
            return a.second<b.second;
        }
    }
};
    string reorganizeString(string s) {
        int seat=0;
        string res="";
        priority_queue<pair<int,char>,vector<pair<int,char>>,cmp>pq;
        int n=s.size();
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        for(auto it: mp){
            int freq=it.second;
            char letter=it.first;
            pair<int,char>curr={freq,letter};
            pq.push(curr);
        }
        while(!pq.empty()){
            pair<int,char>p=pq.top();
            pq.pop();
            if((seat==0) || (res[seat-1]!=p.second)){
                res.push_back(p.second);
                seat++;
                p.first--;
                if(p.first>0){
                    pq.push(p);
                }
            }
            else{
                if(pq.empty()){
                    return "";
                }
                pair<int,char>p2=pq.top();
                pq.pop();
                res.push_back(p2.second);
                seat++;
                p2.first--;
                if(p2.first>0){
                    pq.push(p2);
                }
                pq.push(p);
            }
        }
        return res;
    }
};