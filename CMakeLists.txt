cmake_minimum_required(VERSION 3.0.0)
project(cmake_test VERSION 1.0.0
                   DESCRIPTION "cmake project test"
                   LANGUAGES CXX)
                
set(CMAKE_CXX_STANDARD 14)

# Eigen
find_package(Eigen3 REQUIRED)

#yaml-cpp
find_package(yaml-cpp REQUIRED)
# message(STATUS yaml-cpp)
# message(STATUS ${YAML_CPP_INCLUDE_DIR})
# message(STATUS ${YAML_CPP_LIBRARIES})

# jsoncpp
set(Jsoncpp_INCLUDE_PATH "/usr/include/jsoncpp")
set(Jsoncpp_LIBRARY "/usr/lib/x86_64-linux-gnu/libjsoncpp.so")

#opencv
find_package(OpenCV REQUIRED)

#pcl
find_package(PCL REQUIRED)


add_library(hellolib STATIC src/hello.cpp)
target_include_directories(hellolib PUBLIC include)


add_executable(demo src/main.cpp)
target_link_libraries(demo PUBLIC hellolib)


add_executable(eigenTest src/eigenTest.cpp)
target_link_libraries(eigenTest PUBLIC Eigen3::Eigen)


add_executable(yamlcppTest src/yamlcppTest.cpp)
target_include_directories(yamlcppTest PRIVATE ${YAML_CPP_INCLUDE_DIR})
target_link_libraries(yamlcppTest ${YAML_CPP_LIBRARIES})

add_executable(jsoncppTest src/jsoncppTest.cpp)
target_include_directories(jsoncppTest PRIVATE ${Jsoncpp_INCLUDE_PATH})
target_link_libraries(jsoncppTest ${Jsoncpp_LIBRARY})

add_executable(opencvTest src/opencvTest.cpp)
target_include_directories(opencvTest PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(opencvTest ${OpenCV_LIBS})

add_executable(pclTest src/pclTest.cpp)
target_include_directories(pclTest PRIVATE ${PCL_INCLUDE_DIRS})
target_link_libraries(pclTest ${PCL_LIBRARIES})

 