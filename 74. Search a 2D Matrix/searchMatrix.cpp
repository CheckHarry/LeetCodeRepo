#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    for (vector<int> &row : matrix)
    {
        if (row[0] <= target && target <= row[row.size() - 1])
        {
            int left = 0, right = row.size() - 1;
            while ((right - left) > 1)
            {
                int mid = (left + right) / 2;
                if (row[mid] < target)
                    left = mid;
                else if (row[mid] > target)
                    right = mid;
                else
                    return true;
            }
            if (row[left] == target || row[right] == target)
                return true;
            break;
        }
    }
    return false;
}