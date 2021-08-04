#include <thread>
#include <iostream>

void job(const bool &flag)
{
    using namespace std::chrono_literals;
    while (flag)
    {
        std::cout << "Working T2" << '\n';
        std::this_thread::sleep_for(1s);
    }
}

int main(int argc, char const *argv[])
{
    bool flag = true;
    std::thread t1([&flag]()
                   {
                       using namespace std::chrono_literals;
                       while (flag)
                       {
                           std::cout << "Working T1" << '\n';
                           std::this_thread::sleep_for(1s);
                       }
                   });
    std::thread t2(job, std::ref(flag));

    std::cin.get();
    flag = false;
    t1.join();
    t2.join();
    return 0;
}
