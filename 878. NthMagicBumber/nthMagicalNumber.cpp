#define To_mod 1000000007
#define ll long long



int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}


int size_S(int a, int b, int lcm) {
	return lcm / a + lcm / b - 1;
}

int  get_n_S(int  a, int b, int n, int lcm) {
	int S_size = size_S(a, b, lcm);
	if (n == 0) return 0;
	ll cur = (a * b / (a + b)) * n, left = 0, right = lcm - 1;
	while (true) {
		ll ele_no = cur / a + cur / b;
		if (ele_no == n) {
			return max((cur / a) * a, (cur / b) * b);
		}
		else if (ele_no > n) {
			right = cur;
			cur = (left + cur) / 2;
		}
		else {
			left = cur;
			cur = (right + cur) / 2;
		}
	}

}


int nthMagicalNumber(int n, int a, int b) {
	int lcm = a * b / gcd(a, b);
	int S_size = size_S(a, b, lcm);
	return ((ll)(n / S_size) * (ll)lcm + (ll)get_n_S((ll)a, (ll)b, (ll)n % S_size, lcm)) % To_mod;
}

