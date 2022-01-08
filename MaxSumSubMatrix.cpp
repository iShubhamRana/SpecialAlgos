


/*
Calculate max sum Submatrix from a given matrix.

Kadans variation.
for all combinations of cols O(n*n) calculate sum  for that col range for each row and push in vector. ON that vector perform kadane.


O(n^2) space can be used to store prefix sum which can then be used to calculate col range sums in constant

O(n^3) -Total Time
O(n*n) - Space

*/




#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define INF INT_MAX

using namespace std;
void checkjudge() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt" , "w" , stdout);
#endif
}

int kadane(vector<int> arr) {
    int sum = 0;
    int ans = arr[0];

    for (auto x : arr) {
        sum += x;
        ans = max(ans, sum);
        if (sum < 0)
            sum = 0;
    }
    return ans;
}

int maxSubmatrixSum(vector<vector<int> > matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int ans = INT_MIN;

    vector<vector<int> > preSum(rows, vector<int> (cols, 0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            preSum[i][j] = (j == 0) ? matrix[i][j] : preSum[i][j - 1] + matrix[i][j];
        }
    }

    for (int i = 0; i < cols; i++) {
        for (int j = i; j < cols; j++) {
            vector<int> temp;
            for (int k = 0; k < rows; k++) {
                int sum = (i == 0) ? preSum[k][j] : preSum[k][j] - preSum[k][i - 1];
                temp.push_back(sum);
            }
            ans = max(ans, kadane(temp));
        }
    }

    return ans;

}

int main()
{
    checkjudge();
    vector<vector<int> > matrix = { { 0, -2, -7, 0 },
        { 9, 2, -6, 2 },
        { -4, 1, -4, 1 },
        { -1, 8, 0, -2 }
    };

    cout << maxSubmatrixSum(matrix);

    return 0;
}
