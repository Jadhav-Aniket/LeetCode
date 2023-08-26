#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends
#User function Template for python3

class Solution:
    def solve(self, bt):
        # Code here
        
        
        bt.sort()
        wt = 0
        time = 0
        for i in bt:
            wt += time
            time += i
        #print(bt)
        #print()
        return wt//len(bt)

#{ 
 # Driver Code Starts.
if __name__ == '__main__': 
    t = int(input ())
    for _ in range (t):
        n = int(input())
        bt = list(map(int, input().split()))
        ob = Solution()
        res = ob.solve(bt)
        print(res)
# } Driver Code Ends