#include <list>
#include <vector>
using namespace std;

struct node
{
    int val;
    node *next, *down;
    node() : next(nullptr), down(nullptr){};
    node(node *_next) : next(_next), down(nullptr){};
};

class Skiplist
{
public:
    vector<node *> heads;

    Skiplist()
    {
        node *head = new node();
        heads.push_back(head);
    }

    bool search(int target)
    {
        node *cur = heads.back();
        while (true)
        {
            if (cur->next != nullptr)
            {
                if (cur->next->val < target)
                    cur = cur->next;
                else if (cur->next->val == target)
                    return true;
                else
                {
                    if (cur->down)
                        cur = cur->down;
                    else
                        return false;
                }
            }
            else
            {
                if (cur->down)
                    cur = cur->down;
                else
                    return false;
            }
        }
        return false;
    }

    void add(int num)
    {
        node *cur = heads.back();
        vector<node*> s;
        while (true)
        {
            if (cur->next != nullptr)
            {
                if (cur->next->val < num)
                    cur = cur -> next;
                else if (cur -> next -> val == num)
                    return;
                else
                {
                    if (cur->down)
                    {
                        s.push_back(cur);
                        cur = cur -> down;
                    }
                    else
                        break;
                }
            }
            else
            {
                if (cur->down)
                    {
                        s.push_back(cur);
                        cur = cur -> down;
                    }
                    else
                        break;
            }
        }
    }

    bool erase(int num)
    {
    }
};