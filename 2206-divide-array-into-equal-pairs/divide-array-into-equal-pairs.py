class Solution:
    def divideArray(self, nums: List[int]) -> bool:
            mp = {}
            for num in nums:
                mp[num] = mp.get(num,0) + 1
            flag = True
            for val in mp.values():
                if val%2:
                    flag = False
                    break
            return flag
        