#include <asio.hpp>
#include <iostream>
#define ASIO_STANDALONE
#define _WIN32_WINNT 0x0A00

//Standard blocking call
// int main(int argc, char const *argv[])
// {
//     asio::io_context io;
//     asio::steady_timer t(io, asio::chrono::seconds(5));
//     t.wait();
//     std::cout << "Hello, World!" << '\n';
//     return 0;
// }


//ASync clocking call
void print(const asio::error_code &/*e*/)
{
    std::cout << "Hello, World!" << '\n';
}

int main(int argc, char const *argv[])
{
    asio::io_context io;
    asio::steady_timer t(io, asio::chrono::seconds(5));
    t.async_wait(print);
    io.run();
    return 0;
}



