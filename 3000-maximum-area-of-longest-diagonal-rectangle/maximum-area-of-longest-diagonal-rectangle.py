class Solution:
    def areaOfMaxDiagonal(self, dimensions: List[List[int]]) -> int:
        l, b = dimensions[0]
        for x, y in dimensions:
            if (l * l + b * b) < (x * x + y * y):
                l, b = x, y
            elif (l * l + b * b) == (x * x + y * y) and (l * b < x * y):
                l, b = x, y
        return l * b
