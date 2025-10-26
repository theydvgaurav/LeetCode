class Solution:
    def getSigma(self, n):
        if n <= 0:
            return 0
        return (n * (n + 1)) // 2

    def totalMoney(self, n: int) -> int:
        q = n // 7
        r = n % 7
        sig_q_1 = self.getSigma(q - 1)
        sig_r_q = self.getSigma(r + q)
        sig_q = self.getSigma(q)
        return 28 * q + 7 * sig_q_1 + sig_r_q - sig_q
