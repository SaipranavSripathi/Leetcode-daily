class Solution {
public:
    using info=tuple<int, bool, int>;
    static int maxTwoEvents(vector<vector<int>>& events) {
        const int n=events.size();
        vector<info> time(n*2);
        for(int i=0; i<n; i++){
            int s=events[i][0], e=events[i][1], v=events[i][2];
            time[2*i]={s, 0, v};
            time[2*i+1]={e, 1, v};
        }
        sort(time.begin(), time.end());
        int ans=0, maxV=0, n2=n*2;
        for(auto& [t, isEnd, v]: time){
            if (isEnd) maxV=max(maxV, v);
            else ans=max(ans, maxV+v);
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