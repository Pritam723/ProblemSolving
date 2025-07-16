class Solution:
    def isValid(self, word: str) -> bool:
        if len(word) < 3:
            return False

        hasVowel = False
        hasConsonant = False
        vowels = set("aeiouAEIOU")

        for ch in word:
            if not ch.isalnum():
                return False
            if ch.isalpha():
                if ch in vowels:
                    hasVowel = True
                else:
                    hasConsonant = True

        return hasVowel and hasConsonant