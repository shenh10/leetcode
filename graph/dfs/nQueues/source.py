import pdb
class Solution(object):
    def __init__(self):
        self.result = []
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        self.dfs( 0, n, [])
        print self.result
        s = []
        for solution in self.result:
            s1 = []
            for val in solution:
               line = "" 
               for j in xrange(n):
                    if j == val:
                        line += 'Q'
                    else:
                        line += '.'
               s1.append(line)
            s.append(s1)
        print s
        return s
    def dfs(self, l , n,  path):
        if l == n:
            new_path = list(path)
            self.result.append(new_path)
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
    s.solveNQueens(4)
