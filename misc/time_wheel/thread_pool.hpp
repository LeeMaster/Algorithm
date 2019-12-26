#pragma once

#include <thread>
#include <queue>
#include <functional>
#include <future>
#include <mutex>
#include <vector>
#include <condition_variable>

/**
 * 线程池设计思路
 *  组成部分：
 *    1. 任务队列
 *    2. 工作线程集合
 *  实现：
 *    1. 线程池对象初始化的时候，初始化全部的工作对象，在线程池内的工作对象专门处理 void() 函数类型
 *    2. 提交任务，提交的任务通过包装函数的方法 将有参数的方法转换为 void() 
 *  思考：
 *    1. C++的骚操作还是太多了点吧
 *    2. 完美转发和移动语义准备用起来，使用一堆现代C++ 的特性
 */
namespace tm{
  
  // cxx 11 
  using ThreadTask = std::function<void(void *)>;

  // get hardware cocurrency 
  auto a = std::thread::hardware_concurrency();

  std::atomic<bool> stoped;

  std::atomic<size_t> freed;

  std::vector<std::thread> workers;

  std::mutex mutex;



  class ThreadPool{
    private: 

    public: 
      ThreadPool();

      // Execute a task 
      void Execute(ThreadTask *);

      size_t Free();

    public:
      template<class F, class... Args>
      auto Commit(F&& function, Args&& ... args) -> std::future<decltype(function(args...))>{

      }
  };

} // namespace tm
