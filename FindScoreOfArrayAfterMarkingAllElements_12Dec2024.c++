class Solution {
public:
    using int2=pair<int, int>;
    long long findScore(vector<int>& nums) {
        const int N=100000, n=nums.size();
        bitset<N> mark=0;
        vector<int2> nIdx(n);
        for(int i=0; i<n; i++)
            nIdx[i]={nums[i], i};
        sort(nIdx.begin(), nIdx.end());// If there is a tie, choose the one with the smallest index.
        long long sum=0;
        for(auto& [x, i]: nIdx){
            if (mark[i]) continue;
            sum+=x;
        //    cout<<"x="<<x<<" i="<<i<<" mark:"<<mark[i]<<" sum="<<sum<<endl;
            mark[i]=1;
            if (i>0) mark[i-1]=1;
            if (i<n-1) mark[i+1]=1;
        }
        return sum;
    }
};