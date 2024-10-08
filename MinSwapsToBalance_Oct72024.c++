class Solution {
public:
    static int minSwaps(string& s) {
        int p=0;
        for(char c: s){
            p+=(c=='[')-(c==']');
            if (p<0) p=0;
        }
        return (p+1)/2;
    } 
};


auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();