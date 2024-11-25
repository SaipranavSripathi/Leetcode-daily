string tmp="054321";
class Solution {
public:
    int findPos(string &mask){
        for(int i=0; i<6; i++){ if(mask[i]=='0'){ return i; } }
        return 5;
    }
    int slidingPuzzle(vector<vector<int>>& b) {
        string mask=to_string(b[1][2])+to_string(b[1][1])+to_string(b[1][0])+to_string(b[0][2])+to_string(b[0][1])+to_string(b[0][0]);
        priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>> pq;
        unordered_map<string,int> dp;
        dp[mask]=0;
        pq.push({0,mask});
        while(!pq.empty()){
            auto [moves,s]=pq.top(); pq.pop();
            if(s==tmp){ return dp[s]=moves; }
            int pos=findPos(s);
            if(pos==0){
                swap(s[0],s[3]); 
                if(dp.count(s)==0 or 1+moves<dp[s]) pq.push({moves+1,s}); dp[s]=1+moves;
                swap(s[0],s[3]);
                swap(s[0],s[1]); 
                if(dp.count(s)==0 or 1+moves<dp[s]) pq.push({moves+1,s}); dp[s]=1+moves;
                swap(s[0],s[1]);
            }
            else if(pos==1){
                // 0 2 4
                swap(s[4],s[1]); 
                if(dp.count(s)==0 or 1+moves<dp[s]) pq.push({moves+1,s}); dp[s]=1+moves;
                swap(s[4],s[1]);
                swap(s[0],s[1]); 
                if(dp.count(s)==0 or 1+moves<dp[s]) pq.push({moves+1,s}); dp[s]=1+moves;
                swap(s[0],s[1]);
                swap(s[2],s[1]); 
                if(dp.count(s)==0 or 1+moves<dp[s]) pq.push({moves+1,s}); dp[s]=1+moves;
                swap(s[2],s[1]);
            }
            else if(pos==2){
                // 1 5
                swap(s[2],s[5]); 
                if(dp.count(s)==0 or 1+moves<dp[s]) pq.push({moves+1,s}); dp[s]=1+moves;
                swap(s[2],s[5]);
                swap(s[2],s[1]); 
                if(dp.count(s)==0 or 1+moves<dp[s]) pq.push({moves+1,s}); dp[s]=1+moves;
                swap(s[2],s[1]);
            }
            else if(pos==3){
                // 0 4
                swap(s[0],s[3]); 
                if(dp.count(s)==0 or 1+moves<dp[s]) pq.push({moves+1,s}); dp[s]=1+moves;
                swap(s[0],s[3]);
                swap(s[4],s[3]); 
                if(dp.count(s)==0 or 1+moves<dp[s]) pq.push({moves+1,s}); dp[s]=1+moves;
                swap(s[4],s[3]);
            }
            else if(pos==4){
                // 5 3 1
                swap(s[4],s[3]); 
                if(dp.count(s)==0 or 1+moves<dp[s]) pq.push({moves+1,s}); dp[s]=1+moves;
                swap(s[4],s[3]);
                swap(s[4],s[1]); 
                if(dp.count(s)==0 or 1+moves<dp[s]) pq.push({moves+1,s}); dp[s]=1+moves;
                swap(s[4],s[1]);
                swap(s[5],s[4]); 
                if(dp.count(s)==0 or 1+moves<dp[s]) pq.push({moves+1,s}); dp[s]=1+moves;
                swap(s[5],s[4]);
            }
            else{
                swap(s[5],s[2]); 
                if(dp.count(s)==0 or 1+moves<dp[s]) pq.push({moves+1,s}); dp[s]=1+moves;
                swap(s[5],s[2]);
                swap(s[5],s[4]); 
                if(dp.count(s)==0 or 1+moves<dp[s]) pq.push({moves+1,s}); dp[s]=1+moves;
                swap(s[5],s[4]);
            }
        }
        return -1;
    }
};