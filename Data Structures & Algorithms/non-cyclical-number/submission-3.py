class Solution:
    def isHappy(self, n: int) -> bool:
        visited = set()

        while n not in visited:
            visited.add(n)
            sum_ = self.getSumSq(n)
            if(sum_ == 1):
                return True
            
            n = sum_
        return False

    def getSumSq(self, n: int) -> int:
        ans = 0
        while n != 0:
            ans += (n % 10) * (n % 10)
            n = n // 10
        return ans