import pdb
class Solution(object):
    def __init__(self):
        self.cat = 0
    def totalNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        self.dfs( 0, n, [])
        return self.cat
    def dfs(self, l , n,  path):
        if l == n:
            self.cat += 1
            return
        for i in xrange(n):
            if not self.qualify( i, path):
                continue
            path.append(i)
            self.dfs( l+1, n, path)
            path.remove(i)

    def qualify(self, pos,  path):
        index = len(path)
        if pos in path:
            return False
        for i, val in enumerate(path):
            if index - i == pos - val or index - i == val - pos:
                return False
        return True
if __name__ == '__main__':
    s = Solution()
    s.totalNQueens(8)
