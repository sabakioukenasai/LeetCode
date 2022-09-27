#include <vector>

using std::vector;

class Solution{
private:
    void __hanota(vector<int>& A, vector<int>& B, vector<int>& C, int layer) {
        if (layer == 1) {
            C.push_back(A.back());
            A.pop_back();
            return;
        }
        __hanota(A, C, B, layer - 1);
        __hanota(A, B, C, 1);
        __hanota(B, A, C, layer - 1);
        return;
    }
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        __hanota(A, B, C, A.size());
    }
};