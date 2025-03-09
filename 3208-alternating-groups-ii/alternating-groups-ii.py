class Solution:
    def numberOfAlternatingGroups(self, colors: List[int], k: int) -> int: 
        n = len(colors)
        cnt,l = 0, 0
        for right in range(n + k - 1):
            if right > 0 and colors[right % n] == colors[(right - 1) % n]:
                l = right  
            
            if right - l + 1 >= k:
                cnt += 1  
        
        return cnt