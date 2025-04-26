class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        mp = {5: 0, 10: 0, 20: 0}
        for bill in bills:
            mp[bill] = mp.get(bill, 0) + 1
            payback = bill - 5
            if payback:
                for b in [20, 10, 5]:
                    c = payback // b
                    if mp.get(b, 0) >= c and c!=0:
                        payback -= c * b
                        mp[b] -= c
                if payback:
                    return False
        return True
