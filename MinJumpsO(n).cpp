/*
if elements in [i,j] can be reached in m steps then maxrange obtained from [i,j] can be reached in 1 + m . This is the sole logic, rest depends on implementation.
We count steps in range and in that range we count maxJump. After steps end, we have walked through all the elements in that range and all the elements after that range will
have injumps as 1 + jumps.

*/







int minjumps(int arr[] , int n) {
	if (n == 1 or n == 0)
		return 0;

	if (arr[0] == 0)
		return -1;

	int maxReach = arr[0];
	int step = arr[0];
	int jumps = 1;
	int i;

	for ( i = 1; i < n; i++) {
		if (i == n - 1)
			return jumps;
		maxReach = max(maxReach, i + arr[i]);
		steps --;

		if (steps == 0) {
			jumps++;
			if (i >= maxReach)
				return -1;
			steps = maxReach - i;
		}
	}

	return jumps;
}
