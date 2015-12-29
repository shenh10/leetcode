from collections import deque
import pdb

class Solution(object):
    def findLadders(self, beginWord, endWord, wordlist):
        """
        :type beginWord: str
        :type endWord: str
        :type wordlist: Set[str]
        :rtype: List[List[int]]
        """
        cur_queue, next_queue, trace = set(), set() , {}
        result = []
        visited = set()
        alphabet = 'abcdefghijklmnopqrstuvwxyz'
        find = 0
        wordlist.add(beginWord)
        trace[beginWord] = []
        wordlist.add(endWord)
        cur_queue.add(beginWord)
        while cur_queue and  find == 0:
            for word in cur_queue:
                visited.add(word)
            for word in cur_queue:
                for i, c in enumerate(word):
                    for j in alphabet:
                        if j == c:
                            continue
                        new_word = word[0:i] + j + word[i+1:]
                        if new_word in wordlist:
                            if new_word in visited:
                                continue
                            else:
                                if new_word == endWord:
                                    find = 1
                                next_queue.add(new_word)    
                                if new_word not in trace.keys():
                                    trace[new_word] = [word]
                                else:
                                    trace[new_word].append(word)
            if find :
                break
            cur_queue, next_queue = next_queue, set()
            print cur_queue
        if find:
            self.backtrace([], result, endWord, trace)
        return result
    def backtrace(self,path,result, word, trace):
        if word not in trace.keys():
            print 'no result'
            return 
        if not trace[word]:
            result.append([word] + path)
        else:
            for w in trace[word]:
                self.backtrace([word]+ path, result, w, trace)

if __name__ == '__main__':
    s = Solution()
    l = ['hot', 'dog']
    wordlist = set(l)
    print s.findLadders('hot', 'dog', wordlist)
