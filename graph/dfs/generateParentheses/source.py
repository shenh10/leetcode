
class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        result = []
        self.dfs(result, n , [], 0)
        s = []
        for solution in result:
            i = 0
            line = ''
            for j in xrange(2*n):
                if i < n and j == solution[i]:
                    line += '('
                    i += 1
                else:
                    line += ')'
            s.append(line)
        return s

    def dfs(self, result, n, path, start):
        if len(path) == n:
            result.append(list(path))
            return 
        for i in xrange(start, 2*n):
            if i > 2* len(path):
               break 
            path.append(i)
            self.dfs( result, n, path, i + 1 )
            del path[-1]
if __name__ == '__main__':
    s = Solution()
    s.generateParenthesis(3)
