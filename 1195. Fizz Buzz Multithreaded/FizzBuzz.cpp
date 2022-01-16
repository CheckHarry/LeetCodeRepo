#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <functional>
using namespace std;




class FizzBuzz {
private:
    int n , num ;
    mutex m;
    condition_variable cv;
public:
    FizzBuzz(int n) {
        this->n = n;
        num = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        for ( ;num <= n;){
            unique_lock<mutex> lk(m);
            cv.wait(lk , [&](){return (num % 3 == 0 && num % 5 != 0) | num > n;});
            if (num > n){
                lk.unlock();
                cv.notify_all();
                break;
            }
            printFizz();
            num ++;
            lk.unlock();
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        for (;num <= n;){
            unique_lock<mutex> lk(m);
            cv.wait(lk , [&](){return (num % 5 == 0 && num % 3 != 0 ) | num > n;});
            if (num > n){
                lk.unlock();
                cv.notify_all();
                break;
            }
            printBuzz();
            num ++;
            lk.unlock();
            cv.notify_all();
            
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        for (;num <= n;){
            unique_lock<mutex> lk(m);
            cv.wait(lk , [&](){return (num % 15 == 0) | num > n;});
            if (num > n){
                lk.unlock();
                cv.notify_all();
                break;
            }
            printFizzBuzz();
            num ++;
            lk.unlock();
            cv.notify_all();
        
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        for (;num <= n;){
            unique_lock<mutex> lk(m);
            cv.wait(lk , [&](){return (num % 5 != 0 && num % 3 != 0) | num > n;});
            if (num > n){
                lk.unlock();
                cv.notify_all();
                break;
            }
            printNumber(num);
            num ++;
            lk.unlock();
            cv.notify_all();
        }
    }
};


int main(){
    FizzBuzz O(300);
    function<void()> printFizz = [](){cout << "Fizz" << '\n';};
    function<void()> printBuzz = [](){cout << "Buzz" << '\n';};
    function<void()> printFizzBuzz = [](){cout << "FizzBuzz" << '\n';};
    function<void(int)> printNumber = [](int i ){cout << i << '\n';};
    thread t1(&FizzBuzz::fizz , &O , printFizz);
    thread t2(&FizzBuzz::buzz , &O , printBuzz);
    thread t3(&FizzBuzz::fizzbuzz , &O , printFizzBuzz);
    thread t4(&FizzBuzz::number , &O , printNumber);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
}