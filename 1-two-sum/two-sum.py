class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mp = {}
        for idx, num in enumerate(nums):
            if mp.get(num) is not None:
                return [idx,nums.index(mp.get(num))]
            else:
                rem = target - num
                mp[rem] = num

        