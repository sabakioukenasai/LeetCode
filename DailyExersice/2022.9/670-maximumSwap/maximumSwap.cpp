#include <algorithm>
#include <vector>
#include <stack>
#include <string>

using std::pair;
using std::stack;
using std::string;
using std::to_string;
using std::vector;

class Solution{
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        const int size = s.size();
        vector<pair<int, int>> posible;

        int right = size - 1, left = -1;
        for (int i = size - 2; i >= 0; --i) {
            if (s[i] > s[right]) {
                posible.emplace_back(left, right);
                right = i;
                left = -1;
            }
            else if (s[i] < s[right]) {
                left = i;
            }
        }
        if (left != -1){
            std::swap(s[right], s[left]);
        }
        else {
            auto ptr = posible.rbegin();
            while(ptr != posible.rend() && ptr->first == -1)
                ++ptr;
            if (ptr != posible.rend())
                std::swap(s[ptr->first], s[ptr->second]);
        }
        return std::atoi(s.c_str());
    }
};