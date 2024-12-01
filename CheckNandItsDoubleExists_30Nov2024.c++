class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            if(mp[2*arr[i]] != 0 or (arr[i]%2==0 and mp[arr[i]/2]!=0))
            return true;
            mp[arr[i]]++;
        }
        int n=arr.size();
            if(mp[2*arr[n-1]] != 0 or (arr[n-1]%2==0 and mp[arr[n-1]/2]!=0))
            return true;
        return false;

    }
};