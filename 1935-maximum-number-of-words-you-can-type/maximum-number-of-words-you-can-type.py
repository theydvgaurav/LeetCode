class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        words = text.split(" ")
        count = 0
    
        for word in words:
            # valid = True
            # for c in brokenLetters:
            #     if c in word:
            #         valid = False
            # if valid:
            #     count+=1
            count += 0 if sum([1 for c in brokenLetters if c in word]) else 1
        
        return count