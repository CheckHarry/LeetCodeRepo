#include <vector>
using namespace std;

class Iterator
{
    struct Data;
    Data *data;

public:
    Iterator(const vector<int> &nums);
    Iterator(const Iterator &iter);

    // Returns the next element in the iteration.
    int next();

    // Returns true if the iteration has more elements.
    bool hasNext() const;
};

class PeekingIterator : public Iterator
{
public:
    int prev, now;
    bool has_next = true;
    PeekingIterator(const vector<int> &nums) : Iterator(nums)
    {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        now = Iterator::next();
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek()
    {
        return now;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next()
    {
        prev = now;
        if (Iterator::hasNext())
        {
            now = Iterator::next();
        }
        else
            has_next = false;
        return prev;
    }

    bool hasNext() const
    {
        return has_next;
    }
};