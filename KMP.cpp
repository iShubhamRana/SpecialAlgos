
//function for prefix
vector<int> prefix_function(string s) {
	int n = s.length();
	vector<int> pi(n, 0);
	for (int i = 1; i < n; i++) {
		int j = pi[i-1];
		while (j > 0 and s[j] != s[i])
			j = p[j - 1];
		if (s[i] == s[j])
			j++;
		pi[i] = j;
	}
	return pi;
}
