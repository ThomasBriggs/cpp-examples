find_package(OpenSSL REQUIRED)
link_libraries(OpenSSL::Crypto)

add_executable(find_dups main.cpp hash.cpp)
