from copy import deepcopy
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        l,r = 0,2
        n = len(nums)
        cnt = 0
        flag = True
        arr = deepcopy(nums)
        while l<=r and r < n :
            if arr[l] == 0:
                arr[l]=1
                for i in range(l+1,l+3):
                    if arr[i] == 1:
                        arr[i] = 0
                    else:
                        arr[i] = 1
                cnt+=1
            l+=1
            r+=1
        return cnt if all(arr[-3:]) else -1

        