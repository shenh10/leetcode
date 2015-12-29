import numpy as np
class Solution(object):
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        if len(board) == 0:
            return
        l, m = len(board), len(board[0])
        mark = np.zeros((l, m), dtype='int32')
        visited = set()
        for i in range(l):
            self.bfs([(i,0)], mark, visited, board, l, m )
            self.bfs([(i, m-1)], mark, visited, board , l,m)
            
        for i in range(m):
            self.bfs([(0,i)], mark, visited, board , l, m)
            self.bfs([(l-1, i)], mark, visited, board , l, m)
        for i in range(l):
            for j in xrange(m):
                if mark[i][j] == 1:
                    board[i][j] = '0'
                else:
                    board[i][j] = 'X'


    def bfs(self, cur, mark, visited, board , l, m):
        _next = []
        while cur or _next:
            _next = []
            for (x, y) in cur:
                if (x, y) in visited or board[x][y] == 'X':
                    continue
                mark[x][y] = 1
                visited.add((x,y))
                for (delta_x, delta_y) in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                    sub_x = x + delta_x
                    sub_y = y + delta_y
                    if self.inRange(sub_x, sub_y, l, m) and board[sub_x][sub_y] == '0' and (sub_x, sub_y) not in visited :
                        _next.append((sub_x,sub_y))
            cur = _next 

    def inRange(self, k, n , l, m):
        if k >= 0 and k < l and n >= 0 and n < m:
            return True
        else:
            return False
if __name__ == '__main__':
    s = Solution()
    board = [['X', 'X', 'X', 'X'], ['X', '0', '0', 'X'],['X', 'X', '0', 'X'], ['X', '0', '0', 'X'] ]
    s.solve(board)
