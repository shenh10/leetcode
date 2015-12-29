
class Solution(object):
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        if len(s) < 4 or len(s) > 12:
            return []
        result = []
        self.dfs(s, [], result, 0)
        result = set(result)
        print result
        return list(result)
    def dfs(self, s, path, result, start):
        if len(path) > 4:
            return
        if start == len(s):
           if len(path) != 4:
                return
           new_path = list(path)
           print new_path
           result.append('.'.join(new_path))
           return
        if s[start] == '0':
            path.append('0')
            self.dfs(s, path, result, start+1)
            del path[-1]
        else:
            for i in xrange(start + 1, len(s) + 1):
                sub = s[start:i]
                if int(sub) >= 0 and int(sub) <= 255:
                    path.append('%s'%int(sub))
                    self.dfs(s, path, result, i)
                    del path[-1]
        
if __name__ == '__main__':
    s = Solution()
    s.restoreIpAddresses("010010")
