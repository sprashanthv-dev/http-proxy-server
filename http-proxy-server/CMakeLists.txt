cmake_minimum_required(VERSION 3.26)
project(http_proxy_server C)

set(CMAKE_C_STANDARD 11)

add_executable(http_proxy_server proxy.c
        websocket.h
        websocket.c
        error_utils.h
        error_utils.c
        req_handler.h
        req_handler.c
        utils.h
        utils.c
        constants.h
        res_handler.h
        res_handler.c
        dns_cache.h
        file_ops.h
        file_ops.c
        dns_cache.c
        proxy.h
        blacklist.h
        blacklist.c
        page_cache.h
        page_cache.c
        dir_ops.h
        dir_ops.c
        content_type.h)

find_package(Threads REQUIRED)
find_package(OpenSSL REQUIRED)

if(THREADS_HAVE_PTHREAD_ARG)
    target_compile_options(http_proxy_server PUBLIC "-pthread")
endif()
if(CMAKE_THREAD_LIBS_INIT)
    target_link_libraries(http_proxy_server "${CMAKE_THREAD_LIBS_INIT}")
endif()

target_link_libraries(http_proxy_server OpenSSL::SSL OpenSSL::Crypto)