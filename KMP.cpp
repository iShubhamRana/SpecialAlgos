
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
bool kmpMatch(string s1, string s2) {
	int n = s1.length(), m = s2.length();
	int i = 0, j = 0;
	vector<int> pi = prefix_function(s2);
	while (i < n) {
		if (s1[i] == s2[j]) {
			j++, i++;
			if (j == m)
				return true;
		} else {
			if (j == 0)i++;
			else j = pi[j - 1];
		}
	}
	return false;
}
