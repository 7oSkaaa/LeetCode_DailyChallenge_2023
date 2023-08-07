// author : Omar Sanad
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        // a function, we will search for the row where the element is likely to be.
        auto bsRow = [&]() {
            int l = 0, r = matrix.size() - 1, ans = 0;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (matrix[mid].front() <= target)
                    ans = mid, l = mid + 1;
                else
                    r = mid - 1;
            }

            return ans;
        };

        // a function to find the first element less than or equal to target in the row where the element is likely to be.
        auto bsColumn = [&](int row) {
            int l = 0, r = matrix.front().size() - 1, ans = 0;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (matrix[row][mid] <= target)
                    ans = mid, l = mid + 1;
                else
                    r = mid - 1;
            }
            return ans;
        };

        int x = bsRow(), y = bsColumn(x);
        // here we reached x, y : which is the first element that is less than or equal to target

        return matrix[x][y] == target;
    }
};
