#include <array>
#include <iostream>
using namespace std;

#define To_mod 1000000007



int mod_mul(int x, int y) {
	return x * y % To_mod;
}

int mod_add(int x, int y) {
	return (x + y) % To_mod;
}


// It is possible to have O(log n) time complexity with matrix multiplication.
// But it is enough for using following method to have 100% faster.

int numTilings_recursive(int n , array<int, 1001> &a) {
	if (n <= 2) return a[n];
	numTilings_recursive(n - 1, a);
	a[n] = mod_add(mod_mul(2, a[n - 1]), a[n - 3]);
	return a[n];
}

int numTilings(int n) {
	array<int, 1001> a = { 1,2,5 };
	return numTilings_recursive(n - 1, a);
}



int main() {
	cout << numTilings(967);
}