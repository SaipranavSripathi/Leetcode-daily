class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        cSum=[]
        s=0
        for i in nums :
            s+=i
            cSum.append(s)
        ans=0
        for i in range(len(cSum)) :
            if cSum[i] >= (s-cSum[i]) and i!=len(cSum)-1 :
                ans+=1
        return ans