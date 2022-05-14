add_library(pHash INTERFACE)
target_link_libraries(pHash INTERFACE ${CMAKE_SOURCE_DIR}/pHash/build/libs/lib/libpHash.so)
target_include_directories(pHash INTERFACE ${CMAKE_SOURCE_DIR}/pHash/build/libs/include)
link_libraries(pHash)

add_executable(main main.cpp)
add_executable(mh_image mh_image.cpp)
add_executable(datapoint datapoints.cpp)
add_executable(hashBits hashBits.cpp)
