#ifndef STACKFUL_CORO_H
#define STACKFUL_CORO_H

#include <thread>
#include <iostream>
#include <chrono>
#include <boost/asio/io_context.hpp>
#include <boost/system/error_code.hpp>
#include <boost/asio/spawn.hpp>

namespace b_a = boost::asio;

class Timer
{
private:
    int count{0};
    int num_threads{0};
    b_a::io_context ioc;
    std::vector<std::chrono::seconds> sec;
    std::vector<std::thread> ioc_threads;
    void timer_async(std::vector<std::chrono::seconds>::size_type, b_a::yield_context);
public:
    explicit Timer(int num_threads_, std::vector<std::chrono::seconds> sec_): num_threads{num_threads_}, ioc{num_threads},
        sec(sec_) { }
    ~Timer();
    void run();
};

#endif // STACKFUL_CORO_H
