#include <vector>
#include <array>
#include <algorithm>
using namespace std;





void ConstructAdjList(const vector<vector<int>>& prerequisites , array<vector<int>, 2001>& to_return) {
	for (const vector<int>& edge : prerequisites) {
		to_return[edge[1]].push_back(edge[0]);
	}
}

int get_color(int node, array<bool, 2001>& black_nodes, array<bool, 2001>& gray_nodes) {
	if (black_nodes[node] == true) return 2;
	else if (gray_nodes[node] == true) return 1;
	else return 0; //white
}

void dfs_visit(int cur_node, bool &is_valid , vector<int>& topological_sorted_vec, array<vector<int>, 2001>& adj_list, array<bool, 2001>& black_nodes, array<bool, 2001>& gray_nodes) {
	gray_nodes[cur_node] = true;
	if (not is_valid) return;
	for (int adj_node : adj_list[cur_node]) {
		if (get_color(adj_node , black_nodes , gray_nodes) == 1) is_valid = false;
		if (get_color(adj_node, black_nodes, gray_nodes) == 0) {
			dfs_visit(adj_node, is_valid ,topological_sorted_vec ,  adj_list, black_nodes, gray_nodes);
			
		}
	}
	black_nodes[cur_node] = true;
	topological_sorted_vec.push_back(cur_node);
}
void dfs(int numCourses ,  bool& is_valid, vector<int>& topological_sorted_vec, array<vector<int> , 2001> &adj_list , array<bool , 2001>& black_nodes , array<bool , 2001>& gray_nodes) {
	for (int node = 0; node < numCourses; node++) {
		if (get_color(node, black_nodes, gray_nodes) == 0) {
			dfs_visit(node, is_valid ,topological_sorted_vec, adj_list, black_nodes, gray_nodes);
			if (not is_valid) return;
		};
	}
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
	array<bool, 2001> black_nodes, gray_nodes;
	black_nodes.fill(false);
	gray_nodes.fill(false);
	vector<int> to_return;
	bool is_valid = true;
	array<vector<int>, 2001> adj_list;
	ConstructAdjList(prerequisites , adj_list);
	dfs(numCourses, is_valid ,to_return, adj_list, black_nodes, gray_nodes);
	reverse(to_return.begin() , to_return.end());
	if (is_valid) return to_return;
	else return vector<int>({});
}



int main() {
	vector<vector<int>> pre({ {1,0},{2,0},{3,1},{3,2} });
	vector<vector<int>> pre2({ { 1,0 } , {0 , 1} });
	findOrder(4, pre);
	findOrder(2, pre2);

}