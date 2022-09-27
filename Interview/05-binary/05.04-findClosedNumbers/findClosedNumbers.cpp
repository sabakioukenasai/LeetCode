#include <vector>

using std::vector;

// 0ms > 100%, 5.8MB > 94.34%
class Solution{
public:
    vector<int> findClosedNumbers(int num) {
        unsigned int window2b = 0x3, probemask = 0x2, cnt = 0x1;
        int copynum = num;
        vector<int> answer(2, -1);
        for (int i = 0; i < 30; ++i) {
            if (((copynum & window2b) ^ probemask) == 0) {
                answer[1] = copynum ^ window2b;
                break;
            }
            if ((copynum & (probemask ^ window2b)) == 0) {
                copynum ^= probemask ^ window2b;
                copynum &= ~cnt;
                cnt <<= 1;
            }
            window2b <<= 1;
            probemask <<= 1;
        }
        window2b = 0x3;
        probemask = 0x1;
        cnt = 0x1;
        for (int i = 0; i < 30; ++i) {
            if (((num & window2b) ^ probemask) == 0) {
                answer[0] = num ^ window2b;
                break;
            }
            if ((num & probemask) != 0) {
                num ^= probemask;
                num |= cnt;
                cnt <<= 1;
            }
            probemask <<= 1;
            window2b <<= 1;
        }
        return answer;
    }
};