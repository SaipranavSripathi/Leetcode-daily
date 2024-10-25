class Solution {
public:
    static vector<string> removeSubfolders(vector<string>& folder) {
        const int n=folder.size();
        sort(folder.begin(), folder.end());
        vector<string> ans={folder[0]};
    //    ans.reserve(40000);
        string prev=folder[0];
        for(int i=1; i<n; i++){
            string s=folder[i];
            if (s.find(prev+'/')!=0){
                ans.push_back(s);
                prev=s;
            }
        }
        return ans;
    }
};


auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();