#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
using namespace std;

class FooBar {
private:
    int n;
    mutex m;
    bool pass = false;
    condition_variable cv;
public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            
        	// printFoo() outputs "foo". Do not change or remove this line.
        
            unique_lock<mutex> lk(m);
            cv.wait(lk , [&](){return ! pass;});
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            pass = true;
            lk.unlock();
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lk(m);
            cv.wait(lk , [&](){return pass;});
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            pass = false;
            lk.unlock();
            cv.notify_one();
        }
    }
};