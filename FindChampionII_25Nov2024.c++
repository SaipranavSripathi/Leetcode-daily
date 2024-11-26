class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> adj(n,0);
        for(auto x:edges){
            adj[x[1]]++;
        }
        int m=INT_MAX;
        for(auto x:adj){
            m=min(m,x);
        }
        int c=0,ans=-1;
        for(int i=0;i<n;i++){
            if(adj[i]==m){
                c++;
                ans=i;
            }
        }
        return c==1?ans:-1;
    }
};