class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans=0;
        bool flag=true;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<pref.size();j++){
                flag=true;
                if(words[i][j]!=pref[j]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                ans++;
            }
        }
        return ans;
    }
};