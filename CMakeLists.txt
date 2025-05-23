cmake_minimum_required(VERSION 3.27)
project(Data_Estructure_C)

set(CMAKE_CXX_STANDARD 17)

add_executable(Data_Estructure_C main.cpp
        core/BigO/Bigo.cpp
        core/LinkedList/LinkedList.cpp
        core/LinkedList/LinkedList.h
        core/DoubleLinkedList/DoubleLinkedList.cpp
        core/DoubleLinkedList/DoubleLinkedList.h
        core/Stack/Stack.cpp
        core/Stack/Stack.h
        core/Queue/Queue.cpp
        core/Queue/Queue.h
        RingList/RingList.cpp
        RingList/RingList.h
        MatrizDispersa/MatrizDispersa.cpp
        MatrizDispersa/MatrizDispersa.h
        MatrizDispersa/List_Encabezado.cpp
        MatrizDispersa/List_Encabezado.h
        core/Stack/StackVector.cpp
        core/Stack/ReverseString.md
        core/Stack/SortStack.md
        core/Stack/QueueUsingTwoStacks.h
        tree/Node.cpp
        tree/Node.h
        tree/BinarySearchTree.cpp
        tree/BinarySearchTree.h
        tree/treeBk.cpp
        tree/treeB.md
        Grafo/Grafo.md
        Grafo/PriorityQueue.md
        Grafo/CostoMin.md
        Criptografo/Criptografo.h
        Criptografo/Criptografo.md
        Criptografo/x.md
        Criptografo/y.md
        Criptografo/busca.cpp
        "arbol/ArbolBinario .cpp"
        core/LinkedList/Lista_Simple/IDisposable.cpp
        core/LinkedList/Lista_Simple/Node.cpp
        core/LinkedList/Lista_Simple/LinkedList.cpp
)
