class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(),nums.end());
        long long ans=0;
        while(k>0){
            int x=pq.top();
            pq.pop();
            ans+=x;
            int c=x/3;
            if(c*3<x)
            c++;
            pq.push(c);
            k--;
            //cout<<ans<<endl;
        }
        return ans;
    }
};