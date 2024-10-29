//Pruning Early stop version 3ms 95.65%
class Solution {
public:
    vector<vector<int>> dp;
    int n, m;
    int f(int i, int j, int prev, vector<vector<int>>& grid){
        if (i<0 || j<0 ||i>=n || j>=m) return 0;
        int x=grid[i][j];
        if (x<=prev) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int max_move=1+f(i-1, j+1, x, grid);
        for (int i0=i; i0<=i+1; i0++){
            if (max_move==m-j) break;// early stop pruning
            max_move=max(max_move, 1+f(i0, j+1, x, grid));
        }
        return dp[i][j]=max_move;
    }
    int maxMoves(vector<vector<int>>& grid) {
        n=grid.size(), m=grid[0].size();
        dp.assign(n, vector<int>(m, -1));
        int ans=0;
        for (int i=0; i<n; i++){
            if (ans==m) break;// early stop
            ans=max(ans, f(i, 0, -1, grid));
        }
        return ans-1;
    }
};


auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();