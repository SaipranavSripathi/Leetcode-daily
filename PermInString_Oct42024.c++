class Solution {
public:
    bool check(int c1[],int c2[]){
        for(int i=0;i<26;i++){
            if(c1[i]!=c2[i])
            return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int c1[26],c2[26];
        if(s1.size()>s2.size())
        return false;
        for(int i=0;i<26;i++){
            c1[i]=0;
            c2[i]=0;
        }
        for(int i=0;i<s1.size();i++){
            c1[s1[i]-'a']++;
            c2[s2[i]-'a']++;
        }
        if(check(c1,c2))
        return true;
        for(int i=s1.size();i<s2.size();i++){
            c2[s2[i]-'a']++;
            c2[s2[i-s1.size()]-'a']--;
            if(check(c1,c2))
            return true;
            //cout<<i<<endl;
        }
        return false;
    }
};