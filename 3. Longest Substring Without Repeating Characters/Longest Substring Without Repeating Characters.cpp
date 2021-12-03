#include <string>
#include <array>
using namespace std;





int lengthOfLongestSubstring(string s) {
	array<int, 200> cur_char_bag;
	for (int i = 0; i < 200; i++) cur_char_bag[i] = -1;
	int cur_len = 0 , max_len = 0 , index = 0 , left_index = 0;
	for (char x : s) {
		if (cur_char_bag[x] == -1) cur_len += 1;
		else {
			cur_len = index - cur_char_bag[x];
			for (int i = left_index; i < cur_char_bag[x]; i++) cur_char_bag[s[i]] = -1;
			left_index = cur_char_bag[x] + 1;
		}
		cur_char_bag[x] = index;
		index++;
		if (max_len < cur_len) max_len = cur_len;
	}
	return max_len;
}


