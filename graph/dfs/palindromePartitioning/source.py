


class Solution(object):
    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        l = len(s)
        is_palindrom = [ [ False for i in xrange(l)] for j in xrange(l) ]
        for i in reversed(xrange(0, l)):
            for j in xrange(i,l):
                is_palindrom[i][j] = ( s[i] == s[j] and ( (j - i ) < 2 or is_palindrom[i+1][j-1] ) )
        result = [ [] for i in xrange(l) ]
        for i in reversed(xrange(0, l)):
            for j in xrange(i,l):
                if(is_palindrom[i][j]):
                    if j+1 < l:
                        for p in result[j+1]:
                            result[i].append( [ s[i:j+1]]+  p )
                    else:
                        result[i].append([s[i:j+1]]) 
        return result[0] 
if __name__ == '__main__':
    s = Solution()
    s.partition('aab')
