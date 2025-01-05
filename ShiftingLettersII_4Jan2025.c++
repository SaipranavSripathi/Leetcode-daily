class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int v=0,n=s.size();
        vector<int> total(n,0);
        for(int i=0;i<shifts.size();i++){
            if(shifts[i][2]==0)
            v=-1;
            else
            v=1;
            total[shifts[i][0]]+=v;
            if(shifts[i][1]<n-1){
                total[shifts[i][1]+1]+=-v;
            }
        }
        total[0]=total[0]%26;
        for(int i=1;i<n;i++){
            total[i]=(total[i]+total[i-1])%26;
        }
        string ans="";
        for(int i=0;i<n;i++){
            //cout<<total[i]<<endl;
            char c='a'+((s[i]-'a'+total[i]+26)%26);
            ans+=c;
        }
        return ans;
    }
};