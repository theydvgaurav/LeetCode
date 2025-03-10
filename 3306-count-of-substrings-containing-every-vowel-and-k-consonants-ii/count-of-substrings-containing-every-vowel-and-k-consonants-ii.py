class Solution:
    def countOfSubstrings(self,word: str, k: int) -> int:
        return self.atleast(k, word) - self.atleast(k + 1, word)

    def atleast(self,k, word):
        count = consonants = left = 0
        freq = {}
        n = len(word)
        vowels = {'a', 'e', 'i', 'o', 'u'}

        for right in range(n):
            ch = word[right]
            if ch not in vowels:
                consonants += 1

            freq[ch] = freq.get(ch, 0) + 1

            while consonants >= k and self.hasAllVowels(freq):
                count += (n - right)
                leftChar = word[left]
                if leftChar not in vowels:
                    consonants -= 1
                freq[leftChar] -= 1
                if freq[leftChar] == 0:
                    del freq[leftChar]
                left += 1

        return count

    def hasAllVowels(self,freq):
        return all(freq.get(v, 0) > 0 for v in "aeiou")
       
