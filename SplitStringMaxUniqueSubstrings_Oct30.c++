class Solution {
public:
    unordered_set<string_view> word;
    char n, maxCnt=0;
    void f(char i, char cnt, string& s){
        // the remaining substring can not increase maxCnt
        if (n-i<=maxCnt-cnt) return ;// prune
        if (i>=n) {
            maxCnt=max(maxCnt, cnt);
            return ;
        }
        for(char j=i; j<n; j++){
            string_view t(s.data()+i, j-i+1);
            if (word.count(t)) continue;
            word.insert(t);
            f(j+1, cnt+1, s);
            word.erase(t);// backtrack
        }

    }
    int maxUniqueSplit(string& s) {
        n=s.size();
        word.reserve(n);
        char cnt=0;
        f(0, cnt, s);
        return maxCnt;  
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();