class Solution:
    def isHappy(self, n: int) -> bool:
        slow, fast = n, self.sumSquareDigits(n)

        while slow != fast:
            slow = self.sumSquareDigits(slow)
            fast = self.sumSquareDigits(self.sumSquareDigits(fast))
        
        return True if fast == 1 else False
    
    def sumSquareDigits(self, n: int) -> int:
        res = 0
        while n > 0:
            res += (n % 10) * (n % 10)
            n = n // 10
        return res