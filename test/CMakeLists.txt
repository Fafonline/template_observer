cmake_minimum_required(VERSION 2.6)

set (TARGET test_template_observer)


set (SRC_FILE main.cpp)

add_executable(${TARGET} ${SRC_FILE})

install(TARGETS ${TARGET}
        DESTINATION CMAKE_INSTALL_PREFIX/bin)

