class Bank:

    def __init__(self, balance: List[int]):
        self.acc = balance

    def transfer(self, account1: int, account2: int, money: int) -> bool:
        if account1 > len(self.acc) or account1 < 0 or account2 > len(self.acc) or account2 < 0 or money < 0:
            return False
        debit_acc_bal = self.acc[account1-1]
        if debit_acc_bal >= money:
            self.acc[account1-1] = self.acc[account1-1] - money
            self.acc[account2-1] = self.acc[account2-1] + money
            return True
        return False

    def deposit(self, account: int, money: int) -> bool:
        if account > len(self.acc) or account < 0 or money <0:
            print(account, money, len(self.acc))
            return False
        self.acc[account-1] = self.acc[account-1] + money
        return True
        

    def withdraw(self, account: int, money: int) -> bool:
        if account > len(self.acc) or account < 0 or money <0:
            return False
        if self.acc[account-1] < money:
            return False
        self.acc[account-1] = self.acc[account-1] - money
        return True
        


# Your Bank object will be instantiated and called as such:
# obj = Bank(balance)
# param_1 = obj.transfer(account1,account2,money)
# param_2 = obj.deposit(account,money)
# param_3 = obj.withdraw(account,money)