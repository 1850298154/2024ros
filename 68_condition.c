
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

#include <iostream>


pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int ready = 0;

void *worker_thread(void *arg)
{
    std::cout << "3. unique_lock<std::mutex> lock(mutex_) start\n";
    pthread_mutex_lock(&mutex);
    while(!ready)  // ready = 0
    {
        std::cout << "4. " << ready << " ready_ wait start\n";
        pthread_cond_wait(&cond, &mutex); // 线程等待条件变量通知
        std::cout << "11. " << ready << " ready_  wait end\n";
    }

    // 条件满足后执行操作
    // printf("Worker thread is doing work\n");
    std::cout << "12. Worker thread is doing work\n";
    std::cout << "13. unique_lock<std::mutex> lock(mutex_) end\n";
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main()
{
    std::cout << "1. main() start\n";
    pthread_t worker;
    pthread_create(&worker, NULL, worker_thread, NULL);

    std::cout << "2. sleep_for(std::chrono::seconds(1))  start\n";
    // 模拟工作完成后唤醒线程
    sleep(2);
    std::cout << "5. sleep_for(std::chrono::seconds(1))  end\n";
        std::cout << "6. lock_guard<std::mutex> guard(mutex_) start\n";
    pthread_mutex_lock(&mutex);
    ready = 1;
    pthread_mutex_unlock(&mutex);
        std::cout << "7. lock_guard<std::mutex> guard(mutex_) end\n";
    std::cout << "8. cv_.notify_one() start\n";
    pthread_cond_signal(&cond); // 唤醒等待线程
    std::cout << "9. cv_.notify_one() end\n";

    std::cout << "10. worker.join() start\n";
    pthread_join(worker, NULL);
    std::cout << "14. worker.join() end\n";
    return 0;
}
