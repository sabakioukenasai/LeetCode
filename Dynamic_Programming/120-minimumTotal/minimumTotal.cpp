#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

class Solution{
public:
    int minimumTotal(vector<vector<int>> &triangle){
        const size_t len = triangle.size();
        vector<int> total = vector(triangle[len - 1]);

        for (int i = len - 2; i >= 0; --i){
            for (int j = 0; j <= i; ++j){
                int temp = triangle[i][j];
                if (total[j] + temp < total[j + 1] + temp)
                    total[j] += temp;
                else
                    total[j] = total[j + 1] + temp;
                cout << total[j] << ", ";
            }
            cout << endl;
        }
        return total[0];
    }
};