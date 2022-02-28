#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


Node* cloneGraph(Node* node) {
    if (!node) return nullptr;
    queue<Node*> S;
    unordered_map<Node* , Node*> mapping;
    unordered_set<Node*> seen;
    S.push(node);
    while (!S.empty()){
        queue<Node*> S_new;
        while (!S.empty()){
            if (seen.find(S.front()) == seen.end()){
                if (mapping.find(S.front()) == mapping.end()){
                    Node *to_insert = new Node(S.front()->val);
                    mapping.insert(pair {S.front() , to_insert});
                }
                for (Node* &node : S.front()->neighbors) {
                    if (mapping.find(node) == mapping.end()){
                        Node *to_insert = new Node(node->val);
                        mapping.insert(pair {node , to_insert});
                    }
                    mapping[S.front()]->neighbors.push_back(mapping[node]);
                    if(seen.find(node) == seen.end()) S_new.push(node);
                }
                seen.insert(S.front());
            }
            S.pop();
        }
        S = std::move(S_new);
    }
}