cmake_minimum_required(VERSION 3.27)
project(Data_Estructure_C)

set(CMAKE_CXX_STANDARD 17)

add_executable(Data_Estructure_C main.cpp
        BigO/Bigo.cpp
        ClassAndPointers/Cookie.cpp
        ClassAndPointers/Cookie.h
        LinkedList/LinkedList.cpp
        LinkedList/LinkedList.h
        DoubleLinkedList/DoubleLinkedList.cpp
        DoubleLinkedList/DoubleLinkedList.h
        Stack/Stack.cpp
        Stack/Stack.h
        Queue/Queue.cpp
        Queue/Queue.h
        RingList/RingList.cpp
        RingList/RingList.h
)
