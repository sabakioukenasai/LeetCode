

class Solution{
public:
    int preimageSizeFZF(int k){
        unsigned long long  left = 0, right = 5 * (unsigned long long)k, mid = (left + right) >> 1;
        while (left <= right){
            int factor = getFiveFactor(mid);
            if (factor < k){
                left = mid + 1;
            }
            else if (factor > k) {
                right = mid - 1;
            }
            else {
                return 5;
            }
            mid = (left + right) >> 1;
        }
        return 0;
    }
private:
    unsigned long long getFiveFactor(unsigned long long x){
        unsigned long long cnt = x / 5, i = cnt;
        while(i){
            i /= 5;
            cnt += i;
        }
        return cnt;
    }
};
