#include <vector>
#include <unordered_set>

using std::unordered_set;
using std::vector;

class Solution{
public:
    int flipLights(int n, int presses) {
        vector<vector<int>> table = {
            {0x0},
            {0b1001, 0b101010, 0b10101, 0b111111},
            {0b111111, 0b10101, 0b101010, 0b11100, 0b100011, 0b110110},
            {0b100011, 0b11100, 0b110110, 0b0},
            {0b1001}
            };
        vector<int> masks = {0b0, 0b1, 0b11, 0b111, 0b1111, 0b11111, 0b111111};
        vector<vector<int>> map = {
            {0},
            {1},
            {0, 2},
            {3, 1},
            {0, 2, 4}
        };
        int mask = presses > 6 ? 0b111111 : masks[presses];
        vector<int> shrink = n <= 4 ? map[n] : (n % 2 == 0 ? map[4] : map[3]);

        unordered_set<int> conditions;
        for (int i : shrink) {
            for (int snap : table[i]) {
                conditions.emplace(snap & mask);
            }
        }
        return conditions.size();
    }
};