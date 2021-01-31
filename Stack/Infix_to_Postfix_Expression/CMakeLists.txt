cmake_minimum_required(VERSION 3.17)
project(PostfixExpression)

set(CMAKE_CXX_STANDARD 20)
set( CMAKE_BUILD_TYPE Debug )
add_executable(PostfixExpression main.cpp MyStack.h ListNode.h ListNode.h)