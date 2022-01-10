/*
Here we are doing regular merge the catch here is that.

If there are two number A and B then storing A+B*N   N>A and B then we can at any point of time extract A and B by % and /.
This can be used while merging and we can store and read at the same time. And in the end extract the values we stored.

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

void mergethem (vector<int> a , vector<int> b) {

    int mx = INT_MIN;
    for (auto x : a)
        mx = max(mx, x);
    for (auto x : b)
        mx = max(mx, x);

    mx++;

    int i = 0, j = 0, n = a.size() , m = b.size(), k = 0;

    while (i < n and j < m and k < (n + m)) {
        int e1 = a[i] % mx;
        int e2 = b[j] % mx;

        if (e1 <= e2) {
            if (k < n) {
                a[k] += e1 * mx;
            } else {
                b[k - n] = e1 * mx;
            }
            i++;
            k++;
        } else {
            if (k < n) {
                a[k] += e2 * mx;
            } else {
                b[k - n] += e2 * mx;
            }
            j++;
            k++;
        }

    }

    while (i < n) {
        int e = a[i] % mx;
        if (k < n)
            a[k] += e * mx;
        else
            b[k - n] += e * mx;
        i++;
        k++;
    }

    while (j < m) {
        int e = b[j] % mx;
        if (k < n)
            a[k] += e * mx;
        else
            b[k - n] += e * mx;
        j++;
        k++;
    }

    for (auto &x : a) {
        x /= mx;
        cout << x << " ";
    }
    cout << endl;


    for (auto &x : b) {
        x /= mx;
        cout << x << " ";
    }


}

