#include <thread>
#include <mutex>
#include <condition_variable>
class FooBar {
private:
    int n;
    std::mutex mtx;
    std::condition_variable cv;
    bool f1,f2;
public:
    FooBar(int n) {
        this->n = n;
        f1 = false;
        f2 = true;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lck(mtx);
            cv.wait(lck, [this]{ return f2; }); 
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            f1 = true;
            f2 = false;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lck(mtx);
            cv.wait(lck, [this]{ return f1; }); 
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            f2 = true;
            f1 = false;
            cv.notify_all();
        }
    }
};