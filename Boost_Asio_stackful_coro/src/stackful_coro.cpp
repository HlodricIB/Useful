#include <functional>
#include <boost/asio/steady_timer.hpp>
#include "stackful_coro.h"

Timer::~Timer()
{
     std::cout << "Destructor called" << std::endl;
     ioc.stop();
     for (auto& t : ioc_threads)
     {
         if (t.joinable())
         {
             t.join();
         }
     }
}

void Timer::run()
{
    std::vector<std::string>::size_type num_coroutines = sec.size();
    for (std::vector<std::string>::size_type i = 0; i != num_coroutines; ++i)
    {
        b_a::spawn(ioc, std::bind(&Timer::timer_async, this, i, std::placeholders::_1));
    }
    ioc_threads.reserve(num_threads - 1);
    for (int i = 0; i != (num_threads - 1); ++i)
    {
        ioc_threads.emplace_back(std::thread([&ioc = ioc] () {
            ioc.run();
            std::cout << "io_context associated with thread pool finished work" << std::endl;
        }));
    }
    ioc.run();
}

void Timer::timer_async(std::vector<std::chrono::seconds>::size_type i, b_a::yield_context yield)
{
    std::cout << "Timer: " << sec[i].count() << " starts" << "; count = " << count << std::endl;
    std::cout << "Thread id: " << std::this_thread::get_id() << std::endl;
    b_a::steady_timer _timer1(ioc);
    _timer1.expires_after(sec[i]);
    //_timer1.async_wait(yield);
    _timer1.wait();
    ++count;
    std::cout << "Timer: " << sec[i].count() << " expired" << "; count = " << count << std::endl;

    std::cout << "Timer: " << sec[i].count() << " starts" << "; count = " << count << std::endl;
    std::cout << "Thread id: " << std::this_thread::get_id() << std::endl;
    b_a::steady_timer _timer2(ioc);
    _timer2.expires_after(sec[i]);
    _timer2.async_wait(yield);
    ++count;
    std::cout << "Timer: " << sec[i].count() << " expired" << "; count = " << count <<std::endl;
}
