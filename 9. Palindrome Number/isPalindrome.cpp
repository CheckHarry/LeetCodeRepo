#include <string>
#include <iostream>
using namespace std;


bool isPalindrome(int x){
	if (x < 0) return false;
	string tmp = "";
	while (x != 0){
		int n = x%10;
		tmp += (char) n + 48;
		x = (x - n)/10;
	}
	for (int i = 0 ; i < tmp.size()/2 ; i ++){
		if (tmp[i] != tmp[tmp.size() - 1 - i]) return false;
	}
	return true;
}

int main(){
	int x ;
	cin >> x;
	cout << isPalindrome(x);
}