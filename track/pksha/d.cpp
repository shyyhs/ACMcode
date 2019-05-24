#include <vector>
#include <algorithm>

int solution(vector<int>& A) {
    int ans = A[0];
    for (int i = 1; i < A.size(); i++) {
        if (ans > A[i]) {
            ans = A[i];
        }
    }
    return ans;
}
