class Solution:
    def computeGCD(self,x, y):
        while(y):
            x, y = y, x % y
        return abs(x)
    def minOperations(self, nums: List[int], numsDivide: List[int]) -> int:
        ans=numsDivide[0]
        for i in numsDivide:
            ans=self.computeGCD(ans,i)
        nums.sort()
        # print(ans,nums)
        cnt=0
        for i in nums:
            if ans%i==0:
                return cnt
            cnt+=1
        return -1
        