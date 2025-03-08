class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        res = 100000
        for i in range(0,len(blocks)-k+1):
            mp = {}
            for ch in blocks[i:i+k]:
                mp[ch] = mp.get(ch,0) + 1
            res = min(res,mp.get("W",0))
        return res
         