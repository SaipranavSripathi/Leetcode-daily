// class Solution {
// public:
//     vector<int> sumPrefixScores(vector<string>& words) {
//         map<string, int> mp;
//         for(int i=0;i<words.size();i++){
//             string t="";
//             for(auto x:words[i]){
//                 t+=x;
//                 mp[t]++;
//             }
//         }
//         vector<int> ans;
//         for(int i=0;i<words.size();i++){
//             string t="";
//             int s=0;
//             //cout<<words[i]<<endl;
//             for(auto x:words[i]){
//                 t+=x;
//                 s+=mp[t];
//                 //cout<<s<<" ";
//             }
//             cout<<endl;
//             ans.push_back(s);
//         }
//         return ans;
//     }
// };
class trie{
    public:
        int x;
        trie *v[26];
};
void maketrie(string str,trie* node){
    for(auto &i: str){
        if(node->v[i-'a'] == NULL){
            node->v[i-'a'] = new trie();
            node = node->v[i-'a'];
            node->x = node->x +1 ;
        }else{
            node = node->v[i-'a'];
            node->x = node->x +1 ;
        }
    }
}
void solve(string str,trie* node,int &x){
    trie* p = node;
    for(auto &i: str){
        p = p->v[i-'a'];
        x += p->x;
    }
}
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        trie *node = new trie();
        for(auto &i: words){
            maketrie(i,node);
        }
        int x = 0;
        vector<int> ans;
        for(auto &i: words){
            x = 0;
            solve(i,node,x);
            ans.push_back(x);
        }   
        return ans;
    }
};