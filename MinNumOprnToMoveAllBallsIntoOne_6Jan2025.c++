class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[i]=boxes[i]-'0';
        }
        int c=0;
        vector<int> ans;
        for(int i=0;i<n;i++){
            c=0;
            for(int j=0;j<n;j++){
                c+=abs(i-j)*mp[j];
            }
            ans.push_back(c);
        }
        return ans;
    }
};