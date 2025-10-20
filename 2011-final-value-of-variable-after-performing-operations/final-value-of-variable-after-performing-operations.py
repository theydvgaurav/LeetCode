class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        x = 0
        op_map = {
            "X--": lambda x: x - 1,
            "--X": lambda x: x - 1,
            "++X": lambda x: x + 1,
            "X++": lambda x: x + 1,
        }
        for op in operations:
            x = op_map.get(op)(x)
        return x
