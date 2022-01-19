/*
Given n cities and a salesman wants to travels all the cities. The cost rom each city to every city is given. Find the min cost by salesman to travel all cities and
comeback to the start. 

This is not a algo, But this ques can act as a parent or Bitmasking + Dp questions. Thereore it is important

The problem is TP-hard means there is no quick solution. The solution is 2^n with  Dp optimisation

*/

int tsp(vector<vector<int> > dist , int setOfCities , int city , int n , vector<vector<int> > &dp) {

    //base case
    if (setOfCities == (1 << n) - 1) {
        return dist[city][0];
    }

    if (dp[setOfCities][city] != -1 ) {
        return dp[setOfCities][city];
    }


    //otherwise try all possible solutions
    int ans = INT_MAX;
    for (int choice = 0; choice < n; choice++) {
        //check if city is visited
        if ((setOfCities & (1 << choice)) == 0 ) {
            int subProblem = setOfCities(dist, setOfCities | (1 << choice), choice, n, dp);
            ans = min(ans, subProblem);
        }
    }

    dp[setOfCities][city] = ans;
    return ans;

}
