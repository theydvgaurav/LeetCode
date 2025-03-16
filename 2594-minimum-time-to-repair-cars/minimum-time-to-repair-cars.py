import math
class Solution:
    def check(self,ranks,cars,mid):
        cnt = 0
        for r in ranks:
            cnt += math.floor(math.sqrt(mid//r))
        return cnt >= cars
    def repairCars(self, ranks: List[int], cars: int) -> int:
        l,r = 1,max(ranks)*cars*cars
        res = 0
        while l<=r:
            m = l + (r-l)//2
            if self.check(ranks,cars,m):
                res = m
                r = m - 1 
            else:
                l = m + 1
        return res

        