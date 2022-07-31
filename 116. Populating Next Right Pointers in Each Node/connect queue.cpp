

Node *connect(Node *root)
{
    queue<Node *> layer;
    int nodes_num = 1;
    layer.push(root);
    for (; layer.front() != NULL; nodes_num *= 2)
    {
        for (int i = 0; i < nodes_num - 1; i++)
        {
            Node *temp = layer.front();
            layer.push(temp->left);
            layer.push(temp->right);
            layer.pop();
            temp->next = layer.front();
        }
        layer.push(layer.front()->left);
        layer.push(layer.front()->right);
        layer.pop();
    }
    return root;
}