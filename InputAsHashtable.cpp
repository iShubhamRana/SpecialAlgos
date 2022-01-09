


/*

    A very simple yet creative Idea.

    Lets say we want to check repating elements in array of size n having 0 to n-1 elements.
    We want a hashtable right?
    We can use the input array itself to store the occurences (act as hashtable)

    just take mod % size  of array values and increase that index by size of array.


    Since all the elements are less than n, we can use %n check to count occurrences.

    if element is increase its arr[i]/size > 1. And to check repreating ,
    arr[i] >= 2*size() , This would happen only when we have added two times and never again

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

void hashingUsingInputArray(vector<int> arr) {
    int n = arr.size();
    for (auto x : arr) {
        arr[x % n] = arr[x % n] + n;
    }

    cout << "Repeating elements:" << endl;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 2 * n)
            cout << i;
    }

}


int main()
{
    checkjudge();

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    hashingUsingInputArray(arr);

    return 0;
}
