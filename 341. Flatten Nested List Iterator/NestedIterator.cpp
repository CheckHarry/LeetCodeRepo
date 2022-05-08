#include <vector>
using namespace std;

class NestedInteger
{
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator
{

public:
    vector<int> s;
    int cur = -1;

    static void iterate(vector<int> &v, const NestedInteger &nestedInt)
    {
        if (nestedInt.isInteger())
        {

            v.push_back(nestedInt.getInteger());
        }
        else
        {
            const vector<NestedInteger> &x = nestedInt.getList();
            for (auto &&i : x)
            {
                iterate(v, i);
            }
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList) : cur(-1)
    {
        for (auto &&i : nestedList)
        {
            iterate(s, i);
        }
    }

    int next()
    {
        cur++;
        return s[cur];
    }

    bool hasNext()
    {

        return cur + 1 < s.size();
    }
};