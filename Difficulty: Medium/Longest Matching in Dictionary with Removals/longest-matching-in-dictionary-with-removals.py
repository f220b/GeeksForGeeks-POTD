class Solution:
    def findLongestWord(self, s: str, d: list) -> str:
        # waiting[c] = list of (word_index, position of next needed char)
        waiting = [[] for _ in range(26)]
        for idx, w in enumerate(d):
            waiting[ord(w[0]) - 97].append((idx, 0))

        matched = []
        for ch in s:
            c = ord(ch) - 97
            bucket = waiting[c]
            if not bucket:
                continue
            waiting[c] = []  # new list, so words needing ch again wait for a LATER ch
            for idx, pos in bucket:
                pos += 1
                w = d[idx]
                if pos == len(w):
                    matched.append(w)
                else:
                    waiting[ord(w[pos]) - 97].append((idx, pos))

        # longest first, then lexicographically smallest
        return min(matched, key=lambda w: (-len(w), w), default="")