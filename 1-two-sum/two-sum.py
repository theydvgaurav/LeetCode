class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mp = {}
        for idx, num in enumerate(nums):
            rem = target - num
            if mp.get(rem) is not None:
                return [idx,mp.get(rem)]
            else:
                mp[num] = idx

        