class Solution {
public:
    char findKthBit(int n, int k) {
        if (k==1) return '0';// base case
        int sz=32-__builtin_clz(k);
        int k0=(1<<sz)-k; // reflected number
        if (k0==k) return '1';// k is a symmetry number
    //    cout<<(1<<sz)<<", k="<<k<<endl;
        return (findKthBit(n, k0)=='0')?'1':'0';
    }
};