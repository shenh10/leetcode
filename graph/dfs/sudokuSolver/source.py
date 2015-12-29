
class Solution(object):
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        self.dfs(board, 0, 0)
        return board
    def dfs(self, board, i , j):
        flag = False
        if board[i][j] == '.':
            for k in xrange(9):
                c =  chr(ord('1') + k)
                if self.isValid(board,i, j, c):
                    board[i][j] = c 
                    if j < 8 :
                        flag = self.dfs(board, i, j+1)
                    elif i < 8:
                        flag = self.dfs(board, i+1, 0)
                    else:
                        return True
                    if flag == True:
                        return True
                    else:
                        continue
            board[i][j] = '.'
            return False
        if j < 8 :
            flag = self.dfs(board, i, j+1)
        elif i < 8:
            flag = self.dfs(board, i+1, 0)
        else:
            return True
        return flag
    def isValid(self, board, i, j, k):
        for l in xrange(9):
            if l != j and board[i][l] == k or l != i and board[l][j] == k:
                return False
        for l in xrange( i / 3 * 3, ( i /3 + 1 )* 3 ):
            for m in xrange( j / 3 * 3, ( j /3 + 1 )* 3 ):
                if board[l][m] == k:
                    return False
        return True

if __name__ == '__main__':
    board = [['5','3','.','.','7','.','.','.','.'],
            ['6','.','.','1','9','5','.','.','.'],
            ['.','9','8','.','.','.','.','6','.'],
            ['8','.','.','.','6','.','.','.','3'],
            ['4','.','.','8','.','3','.','.','1'],
            ['7','.','.','.','2','.','.','.','6'],
            ['.','6','.','.','.','.','2','8','.'],
            ['.','.','.','4','1','9','.','.','5'],
            ['.','.','.','.','8','.','.','7','9']]
    s = Solution()
    s.solveSudoku(board)
