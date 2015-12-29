class Trie(object):
    def __init__(self):
        self.isString = False
        self.leaves = {}

    def insert(self, word):
        cur = self
        for c in word:
            if c not in cur.leaves:
                cur.leaves[c] = Trie()
            cur = cur.leaves[c]
        cur.isString = True

class Solution(object):
    def __init__(self):
        self.trie = Trie()
    def findWords(self, board, words):
        """
        :type board: List[List[str]]
        :type words: List[str]
        :rtype: List[str]
        """
        result = []
        if len(board) == 0:
            return result
        for word in words:
            self.trie.insert(word)

        visited = [[False for j in xrange(len(board[0]))] for i in xrange(len(board)) ] 
        for i in xrange(len(board)):
            for j in xrange(len(board[0])):
                self.dfs(board,[], result, self.trie, visited, i, j)
        return list(set(result))
        

    def dfs(self, board, curword, result, trie , visited, i, j):
        m , n= len(board) ,len(board[0])
        if i < 0 or i >= m or j < 0 or j >=n or visited[i][j]:
            return False
        if board[i][j] not in trie.leaves:
            return
        curword.append(board[i][j])
        if trie.leaves[board[i][j]].isString:
            result.append(''.join(curword))
        pos = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        visited[i][j] = True
        for (p, q) in pos:
            self.dfs(board, curword, result, trie.leaves[board[i][j]], visited,  i + p, j + q)
        visited[i][j] = False
        del curword[-1]
        return 

if __name__ == '__main__':
    s = Solution()
    board = ['oaan','etae','ihkr','iflv']
    words = ["oath","pea","eat","rain"]
    print s.findWords( [ list(b) for b in board], words )
