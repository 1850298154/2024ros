#include <iostream>
#include <memory_resource>

void printMemoryUsage(std::pmr::memory_resource* mr) {
    constexpr size_t size = 10;
    
    // 使用指定的内存资源分配内存
    int* arr = static_cast<int*>(mr->allocate(size * sizeof(int)));
    
    for (size_t i = 0; i < size; ++i) {
        arr[i] = i;  // 对数组进行赋值
    }
    
    // 输出数组内容
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    // 释放内存
    mr->deallocate(arr, size * sizeof(int));
}

int main() {
    // 使用标准内存资源
    std::pmr::memory_resource* defaultMemoryResource = std::pmr::get_default_resource();
    std::cout << "Using default memory resource:" << std::endl;
    printMemoryUsage(defaultMemoryResource);
    
    // 使用无状态内存资源
    std::pmr::monotonic_buffer_resource pool;
    std::pmr::memory_resource* poolMemoryResource = &pool;
    std::cout << "Using pool memory resource:" << std::endl;
    printMemoryUsage(poolMemoryResource);
    
    return 0;
}