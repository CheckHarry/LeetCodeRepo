


TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* x = root , *y = nullptr;
        TreeNode* new_node = new TreeNode(val);
        while(x != nullptr){
            y = x;
            if (new_node -> val < x -> val) x = x -> left;
            else x = x -> right;
        }
        if (y == nullptr) return new_node;
        else if (new_node -> val < y -> val) y -> left = new_node;
        else y -> right = new_node;
        return root;
   }