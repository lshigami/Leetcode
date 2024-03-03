class Solution:
    def generate(self, numRows):
        ans = []
        for i in range(numRows):
            v = [0]*(i+1)
            for j in range(i+1):
                if j==0 or j==i:
                    v[j] = 1
                else:
                    v[j] = ans[i-1][j-1] + ans[i-1][j]
            ans.append(v)
        return ans
