class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<int,vector<int>,greater<int>> pq;
        set<int> se;
        for(auto x:arr){
            if(!se.contains(x)){
                pq.push(x);
                se.insert(x);
            }
        }
        int ind=1;
        map<int,int> mp;
        while(pq.size() > 0){
            mp[pq.top()]=ind;
            ind++;
            pq.pop();
        }
        vector<int> ans;
        for(auto x:arr){
            ans.push_back(mp[x]);
        }
        return ans;
    }
};