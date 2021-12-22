#include <vector>
#include <string>
#include <iostream>
using namespace std;





string strWithout3a3b(int a, int b) {
	string to_return;
	if (a + b <= 3) {
		for (int i = 0; i < a; i++) to_return += 'a';
		for (int i = 0; i < b; i++) to_return += 'b';
		return to_return;
	}
	else {
		if (a > b) { 
			if (a - 2 <= 2 * (b - 1) + 2) { 
				string temp = strWithout3a3b(a - 2, b - 1);
				if (temp[temp.size() - 1] == 'a') return temp + "baa";
				else return temp + "aab";
				 }
			else return strWithout3a3b(a - 1, b) + strWithout3a3b(1, 0);
		} 
		else { 
			if (b - 2 <= 2 * (a - 1) + 2) { 
				string temp = strWithout3a3b(a - 1, b - 2);
				if (temp[temp.size() - 1] == 'b') return temp + "abb";
				else return temp + "bba";
			}
			else return strWithout3a3b(a , b - 1) + strWithout3a3b(0 , 1);
		}
	}
}

int main() {
	cout << strWithout3a3b(3,1);
}