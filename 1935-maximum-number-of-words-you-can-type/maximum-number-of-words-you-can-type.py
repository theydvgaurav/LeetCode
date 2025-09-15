class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        cnt=0
        for word in text.split(" "):
            if not any([ch for ch in brokenLetters if word.find(ch)!=-1]):
                cnt+=1
        return cnt
