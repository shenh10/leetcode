
class Solution(object):
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        if k <= 0 or n > k*9 or n < 1*k:
            return []
        result = []
        self.dfs([], result, 0, n, k, 1)
        print result
        return result
        
    def dfs(self, path, result, _sum, target, k, start):
        if len(path) == k:
            if _sum == target:
                new_p = list(path)
                result.append(new_p)
            else:
                return
        if _sum >= target:
            return
        for i in xrange(start, 10):
            if _sum + i > target:
                break
            path.append(i)
            self.dfs(path, result, _sum + i, target, k , i + 1)
            del path[-1]
if __name__ == '__main__':
    s = Solution()
    s.combinationSum3(3, 9)
