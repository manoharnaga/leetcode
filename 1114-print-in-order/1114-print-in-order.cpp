#include <thread>
#include <mutex>
#include <condition_variable>
class Foo {
public:
    std::mutex mtx;
    std::condition_variable cv;
    bool f1,f2;

    Foo() {
        f1 = false;
        f2 = false;
    }

    void first(function<void()> printFirst) {
        std::unique_lock<std::mutex> lck(mtx);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        f1 = true;
        cv.notify_all(); // Signal that function 1 is done
    }

    void second(function<void()> printSecond) {
        std::unique_lock<std::mutex> lck(mtx);
        cv.wait(lck, [this]{ return f1; }); // Wait until function 1 is done
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        f2 = true;
        cv.notify_all(); // Signal that function 2 is done
    }

    void third(function<void()> printThird) {
        std::unique_lock<std::mutex> lck(mtx);
        cv.wait(lck, [this]{ return f2; }); // Wait until function 1 is done
        // printSecond() outputs "second". Do not change or remove this line.
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};