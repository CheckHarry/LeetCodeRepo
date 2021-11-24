#include <iostream>
#include <array>
using namespace std;



// dfs 
int countArrangement(int n) {
	int curpos = 1, ans = 0;
	array<int, 17> seq{0};
	array<int, 17> mask{0};
	while (true)
	{
		int origin = seq[curpos - 1];
		while (true)
		{
			seq[curpos - 1] ++;
			if (seq[curpos - 1] == n + 1 or mask[seq[curpos - 1]] == 0) {
				mask[seq[curpos - 1]] ++;
				mask[origin] --;
				break;
			}
		}
		if (seq[curpos - 1] == n + 1)
			if (curpos == 1) break;
			else
			{
				seq[curpos - 1] = 0;
				curpos--;
				continue;
			}
		if (seq[curpos - 1] % curpos == 0| curpos % seq[curpos - 1]  == 0){
			// move to next pos
			if (curpos == n) ans++;
			else  curpos++;

		}

	}
	return ans;
}


