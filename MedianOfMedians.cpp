/*
The algo is the best algo for kth smallest questions and median findings. It has worst case of O(n) . Insane right?
The algo is a variation of quickselect, we just choose the pivot in sucha a way that the elements are almost equally divided.
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

int findMedian(int arr[] , int n) {
    sort(arr, arr + n);
    return arr[n / 2];
}

int partition(int arr[] , int l , int h, int medOfMedians) {
    int m;
    for (int i = 0; i < h; i++) {
        if (arr[i] == medOfMedians) {
            m = i;
            break;
        }
    }

    swap(arr[l], arr[m]);

    int pivot = arr[l];
    int i = l , j = h ;

    while (i < j) {
        do {i++;} while (arr[i] <= pivot);
        do {j--;} while (j >= 0 and arr[j] > pivot );

        if (i > j)
            break;
        swap(arr[i], arr[j]);
    }

    swap(arr[l] , arr[j]);
    return j;
}

int kthSmallest(int arr[] , int l , int r , int k) {

    if (l < r) {

        int n = r - l ;
        int i = 0, median[(n + 4) / 5];

        for (int i = 0; i < n / 5; i++) {
            median[i] = findMedian(arr + l + i * 5, 5);
        }

        if (i * 5 < n) {
            median[i] = findMedian(arr + l + i * 5 , n % 5);
            i++;
        }

        int medOfMedians = (i == 1) ? median[i - 1] : kthSmallest(median, 0, i, i / 2);



        int j = partition(arr, l, r, medOfMedians);
        if (j == k - 1)
            return arr[k - 1];
        else {
            if (j > k - 1)
                return kthSmallest(arr, l, j, k);
            else
                return kthSmallest(arr, j + 1, r, k);
        }
    }
    return -1;
}

int main() {

    checkjudge();
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k; cin >> k;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl << kthSmallest(arr, 0, n , k );

    return 0;

}
