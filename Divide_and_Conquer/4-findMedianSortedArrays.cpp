#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

class Solution{
private:
    int find_k(vector<int>& A, vector<int>& B, int m, int n, int k){
        int now = 0, A_start = 0, B_start = 0, A_rest = m, B_rest = n;
        cout << "k    " << k << endl;
        do
        {
            int mid = (k - now) / 2;
            int drop = min(min(mid, A_rest), B_rest);
            now += drop;
            cout <<"index "<< A_start + drop - 1 <<", inedx:"<< B_start + drop - 1 << endl;
            if (A[A_start + drop - 1] < B[B_start + drop - 1]){
                A_start += drop;
                A_rest -= drop;
            }
            else{
                B_start += drop;
                B_rest -= drop;
            }
            cout << "now < k -1: " << (now < (k - 1)) << endl;
            cout << A_rest << "   " << B_rest << endl;
        } while (now < (k - 1) && A_rest && B_rest);

        if (A_rest && B_rest){
            if (A_rest){
                cout <<"index "<< A_start + k - now - 1 << endl;
                return A[A_start - now - 1 + k];
            }
            else{
                cout <<"index "<< B_start + k - now - 1 << endl;
                return B[B_start - now - 1 + k];
            }
        }
        else
            return A[A_start] < B[B_start] ? A[A_start] : B[B_start];
    }

public:
    double findMedianSortedArrays(vector<int> nums1, vector<int> nums2){
        int m = nums1.size(), n = nums2.size();
        
        if (m == 0) 
            return (double)(nums2[n / 2] + nums2[(n - 1) / 2]) / 2;
        if (n == 0)
            return (double)(nums1[m / 2] + nums1[(m - 1) / 2]) / 2;

        if ( (m + n) % 2 )
            return (double)find_k(nums1, nums2, m, n, (m + n + 1) / 2);
        else
            return (double)(find_k(nums1, nums2, m, n, (m + n) / 2) + find_k(nums1, nums2, m, n, (m + n) / 2 + 1)) / 2;
    }
};

int main(){
    vector<int> nums1{1,2}, nums2{3,4};
    Solution S;
    double answer = S.findMedianSortedArrays(nums1, nums2);
    cout << answer << endl;
}