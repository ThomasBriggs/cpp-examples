find_package(CURL REQUIRED)
message(STATUS CURLFOUND:${CURL_FOUND})
message(STATUS CURLPATH:${CURL_INCLUDE_DIRS})

add_executable(main main.cpp)
target_link_libraries(main CURL::libcurl)