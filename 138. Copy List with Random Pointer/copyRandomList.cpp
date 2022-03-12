#include <unordered_map>
using namespace std;




class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};




Node* get(Node* node , unordered_map<Node* , Node*> &mapping){
    if (node == nullptr) return nullptr;
    if (mapping.find(node) == mapping.end()) mapping[node] = new Node(node -> val);
    return mapping[node];
}
    
Node* copyRandomList(Node* head) {
    unordered_map<Node* , Node*> mapping;
    Node *cur = head;
    while (cur) {
        Node *new_node = get(cur , mapping);
        new_node -> next = get(cur -> next , mapping);
        new_node -> random = get(cur -> random , mapping);
        cur = cur -> next;
    }
    return mapping[head];
}