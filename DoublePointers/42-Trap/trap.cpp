#include <vector>
#include <assert.h>
#include <iostream>

using std::vector;

class Solution {
public:
    int trap(vector<int>& height) {

        if (height.size() < 3)  // 小于三个格子无法接住雨水 
            return 0;

        int vol = 0;            // 体积为0
        int l = 1, r = height.size() - 1;
        int lh = std::max(height[0], height[1]), rh = height[r];

        while (l < r)
        {
            if (lh <= rh) {
                if (height[l] < lh) {
                    vol += lh - height[l];
                }
                else
                {
                    lh = height[l];
                }
                ++l;
            }
            else
            {
                --r;
                if (height[r] < rh) {
                    vol += rh - height[r];
                }
                else {
                    rh = height[r];
                }
            }
        }
        return vol;
    }
};


// test
int main() {
    std::cout << "Start!" << std::endl;

    Solution S;

    // 柱子数等于0
    vector<int> h0;
    assert(S.trap(h0) == 0);

    // 柱子数等于1
    vector<int> h1 = {1};
    assert(S.trap(h1) == 0);

    // 柱子数等于2
    vector<int> h2 = {1, 2};
    assert(S.trap(h2) == 0);

    // 等于三时，接的到雨水
    vector<int> h3 = {2, 0, 1};
    assert(S.trap(h3) == 1);

    // 等于三时接不到雨水
    vector<int> h4 = {2, 3, 1};
    assert(S.trap(h4) == 0);

    // 山形
    vector<int> h5 = {1, 3, 5, 7, 8, 6, 4, 2};
    assert(S.trap(h5) == 0);

    // 盆地
    vector<int> h6 = {5, 3, 1, 2, 4};
    assert(S.trap(h6) == 6);

    // example one
    vector<int> h7 = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    assert(S.trap(h7) == 6);

    std::cout << "Finished!" << std::endl;
}