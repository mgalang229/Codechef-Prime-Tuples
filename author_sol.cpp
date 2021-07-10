#include <bits/stdc++.h>

using namespace std;

const int inf = (int) 1e6 + 1;

// this function sieves (separates) the prime numbers
vector<bool> Sieve(int n) {
	vector<bool> visited(n, true);
	for (int i = 2; i * i <= n; i++) {
		if (visited[i]) {
			for (int j = i * i; j <= n; j += i) {
				visited[j] = false;
			}
		}
	}
	return visited;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	// precompute the prime numbers and mark their places using boolean vector
	vector<bool> prime = Sieve(inf);
	vector<int> res(inf, 0);
	int cnt = 0;
	// according to the problem statement, 'a' < 'b' < 'c' <= 'n' and 'a' + 'b' = 'c'
	// and if we look at the prime numbers sequence, we can immediately see that 2 can never
	// be 'c' since it is the smallest value in the sequence. However, we can see that if 2
	// is not considered then all possible 'c' values are odd numbers.
	// from observation again:
	// even + even = even
	// odd + odd = even
	// even + odd = odd
	// we can see that exactly one (1) even and one (1) can ONLY form an odd sum, and if we
	// look at the prime number sequence, there is ONLY one even number that is 2. It means
	// that the value of 'a' is ALWAYS equal to 2. In conclusion, any prime number that is
	// added to 2 that produces another prime number, then it is considered as a valid tuple.
	for (int i = 5; i < inf; i++) {
		// check if the current number and the (current number - 2) if they are both prime
		if (prime[i] && prime[i - 2]) {
			// if yes, then increment 'cnt'
			cnt++;
		}
		// set the specific 'cnt' value to the corresponding number (it means that in this
		// current number, there are 'cnt' prime numbers before or equal to it)
		res[i] = cnt;
	}
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		// print the valid tuples up to number 'n'
		cout << res[n] << '\n';
	}
	return 0;
}
