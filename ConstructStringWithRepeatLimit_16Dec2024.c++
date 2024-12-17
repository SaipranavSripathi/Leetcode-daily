class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> cha(26, 0);
        for(int i = 0; i < s.length(); i++){
            cha[s[i]-'a']++;
        }
        int i = 25, tmp = i-1;
        bool nomore = false;
        while(cha[tmp] == 0){
            tmp--;
            if(tmp < 0){
                nomore = true;
                break;
            }
        }
        string ans;
        while(i >= 0){
            int k = 0;
            for(; k < repeatLimit; k++){
                if(cha[i] <= 0) break;
                ans += ('a'+i);
                cha[i]--;
            }
            if(nomore) break;
            if(cha[i] <= 0){
                i = tmp; tmp--;
                if(tmp < 0){
                    nomore = true;
                    continue;
                }
                while(cha[tmp] == 0 && !nomore){
                    tmp--;
                    if(tmp < 0){
                        nomore = true;
                        break;
                    }
                }
            }else if(k == repeatLimit){
                ans += ('a' + tmp);
                cha[tmp]--;
                while(cha[tmp] == 0 && !nomore){
                    tmp--;
                    if(tmp < 0){
                        nomore = true;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};