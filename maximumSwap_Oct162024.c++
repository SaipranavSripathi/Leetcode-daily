class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        for(int i=0;i<s.size();i++){
            int maxi=i;
            for(int j=i+1;j<s.size();j++){
                if(s[j]>s[i] and s[j]>=s[maxi]){
                    maxi=j;
                }
            }
            if(maxi!=i){
                char t=s[i];
                s[i]=s[maxi];
                s[maxi]=t;
                break;
            }
        }
        return stoi(s);
    }
};