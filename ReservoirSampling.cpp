/*
https://www.geeksforgeeks.org/reservoir-sampling/
If we have to choose random k elements from a stream and all the elements should have equal probabilities , then this technique can be used . 
Algo:
make reservoir of k elements and insert first k elements.
traverse from k+1 to n-1 and generate random number from 0 to index and if that random num is <k swap the current position with that index in reservoir.

Proof is pretty Simple . Check the link:

O(n) : Time  O(k):space
Pretty useful when we have very big streams and this algo is used in day to day life


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


void reservoirSampling(int stream[] , int n, int k) {
    int reserve[k];
    for (int i = 0; i < k; ++i)
    {
        reserve[i] = stream[i];
    }
    for (int i = k + 1; i < n; i++) {
        int j = rand() % (i + 1);
        if (j < k) {
            reserve[j] = stream[i];
        }
    }

    for (int i = 0; i < k; i++)
        cout << reserve[i] << " ";

    cout << endl;
}

int main() {

    checkjudge();
    srand(time(0));

    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int k; cin >> k;

    reservoirSampling(arr, n, k);


    return 0;

}
