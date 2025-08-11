class Solution {
public:
    double getAreaDiff(vector<vector<int>>& squares, double line) {
        double aboveLine = 0, belowLine = 0;
        for (auto &square : squares) {
            double y = square[1], side = square[2];
            double squareArea = side * side;

            if (line <= y) {
                // Entire square above the line
                aboveLine += squareArea;
            }
            else if (line >= y + side) {
                // Entire square below the line
                belowLine += squareArea;
            }
            else {
                // Line cuts the square
                double belowHeight = line - y;
                double aboveHeight = side - belowHeight;
                belowLine += belowHeight * side;
                aboveLine += aboveHeight * side;
            }
        }
        return aboveLine - belowLine;
    }

    double getMinY(vector<vector<int>>& squares) {
        double minY = squares[0][1];
        for (auto& s : squares) {
            minY = min(minY, (double)s[1]);
        }
        return minY;
    }

    double getMaxY(vector<vector<int>>& squares) {
        double maxY = squares[0][1] + squares[0][2];
        for (auto& s : squares) {
            maxY = max(maxY, (double)s[1] + s[2]);
        }
        return maxY;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double minY = getMinY(squares);
        double maxY = getMaxY(squares);
        double prec = 1e-5;

        while (maxY - minY > prec) {
            double midY = (minY + maxY) / 2.0;
            double diff = getAreaDiff(squares, midY);
            if (diff > 0) {
                // More area above → move line down
                minY = midY;
            } else {
                // More area below → move line up
                maxY = midY;
            }
        }
        return minY;
    }
};
