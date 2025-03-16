class Solution:
    def check(self,c,k,m):
        cnt = 0
        for can in c:
            cnt += can//m
        return cnt >= k


    def maximumCandies(self, candies: List[int], k: int) -> int:
        if sum(candies) < k:
            return 0
        l,r = 1, max(candies)
        res = 0
        while l<=r:
            m = l + (r-l)//2
            if self.check(candies,k,m):
                res = m
                l = m + 1
            else:
                r = m - 1
        return res