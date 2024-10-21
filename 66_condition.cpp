// g++ -pthread 66_condition.cpp -o 66_condition
// g++ -pthread 66_condition.cpp 

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mutex_;
std::condition_variable cv_;
bool ready_ = false;

void worker_thread()
{
    std::cout << "3. unique_lock<std::mutex> lock(mutex_) start\n";
    std::unique_lock<std::mutex> lock(mutex_);
    while(!ready_)  // ready_ = 0
    {
        std::cout << "4. " << ready_ << " ready_ wait start\n";
        cv_.wait(lock); // 线程等待条件变量通知
        std::cout << "11. " << ready_ << " ready_  wait end\n";
    }

    // 条件满足后执行操作
    std::cout << "12. Worker thread is doing work\n";
    std::cout << "13. unique_lock<std::mutex> lock(mutex_) end\n";
}

int main()
{
    std::cout << "1. main() start\n";
    std::thread worker(worker_thread);

    std::cout << "2. sleep_for(std::chrono::seconds(1))  start\n";
    // 模拟工作完成后唤醒线程
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "5. sleep_for(std::chrono::seconds(1))  end\n";
    {
        std::cout << "6. lock_guard<std::mutex> guard(mutex_) start\n";
        std::lock_guard<std::mutex> guard(mutex_);
        ready_ = true;
        std::cout << "7. lock_guard<std::mutex> guard(mutex_) end\n";
    }
    std::cout << "8. cv_.notify_one() start\n";
    cv_.notify_one(); // 唤醒等待线程
    std::cout << "9. cv_.notify_one() end\n";

    std::cout << "10. worker.join() start\n";
    worker.join();
    std::cout << "14. worker.join() end\n";
    return 0;
}
