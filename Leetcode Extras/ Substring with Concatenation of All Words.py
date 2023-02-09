# This one does give TLE on leetcode but it is pretty much a brute force solution and what i thought

from itertools import permutations


class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        combinations = []
        for idx in range(1, len(words) + 1):
            combinations.extend(list(permutations(words, idx)))
        finalCombinations = []
        for ele in combinations:
            finalCombinations.append("".join(ele))
        len1 = 0
        for idx in range(len(words)):
            len1 += len(words[idx])

        finalCombinations = [i for i in finalCombinations if len(i) == len1]

        output = []
        for i in range(len(s) + 1 - len1):
            if s[i : i + len1] in finalCombinations:
                output.append(i)

        return output
