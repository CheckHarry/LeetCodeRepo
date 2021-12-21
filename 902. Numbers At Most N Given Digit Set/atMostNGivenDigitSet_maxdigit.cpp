#include <math.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;


int atMostNGivenDigitSet_maxdigit(vector<string>& digits, string x) {
	int result_equal = 0;
	int result_smaller = 0;
	for (string dd : digits) {
		if (dd[0] < x[0]) result_smaller++;
		else if (dd[0] == x[0]) result_equal++;
		else break;
	}
	for (int i = 1; i < x.size(); i++) {
		int d_smaller = 0, d_equal = 0;
		for (string dd : digits) {
			if (dd[0] < x[i]) d_smaller++;
			else if (dd[0] == x[i]) d_equal++;
			else break;
		}
		result_smaller = d_smaller * result_equal + digits.size() * result_smaller;
		result_equal = d_equal * result_equal;
	}
	return result_smaller + result_equal;
}


int atMostNGivenDigitSet(vector<string>& digits, int n) {
	string x = "";
	int k = n;
	while (k != 0) {
		x = char(k%10 + 48) + x;
		k = (k - k % 10) / 10;
	}
	int result = 0;
	int L = x.size();
	if (digits.size() > 1) return (pow(digits.size(), L) - 1) / (digits.size() - 1) + atMostNGivenDigitSet_maxdigit(digits, x) - 1;
	else return atMostNGivenDigitSet_maxdigit(digits, x) + x.size() - 1;
}
