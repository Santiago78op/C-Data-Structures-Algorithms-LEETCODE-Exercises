//
// Created by 72358 on 25/09/2024.
//

#include <iostream>
#include "Bigo.h"

namespace algoritmobigo {
    Bigo::Bigo(int num1, int num2) : num1(num1), num2(num2) {}

    int Bigo::getNum1() const {
        return num1;
    }

    void Bigo::setNum1(int num1) {
        Bigo::num1 = num1;
    }

    int Bigo::getNum2() const {
        return num2;
    }

    void Bigo::setNum2(int num2) {
        Bigo::num2 = num2;
    }

    void Bigo::printItemsOn(int num) {
        for (int i = 0; i < num; ++i) {
            std::cout << "Item " << i + 1 << std::endl;
        }
    }

    void Bigo::dropConstant(int num) {
        for (int i = 0; i < num; ++i) {
            std::cout << i << std::endl;
        }

        for (int i = 0; i < num; ++i) {
            std::cout << i << std::endl;
        }
    }

    void Bigo::nExponent(int num) {
        for (int i = 0; i < num; ++i) {
            for (int j = 0; j < num; ++j) {
                for (int k = 0; k < num; ++k) {
                    std::cout << i << j << k << std::endl;
                }
            }
        }
    }

    void Bigo::dropNonDomiant(int num) {
        for (int i = 0; i < num; ++i) {
            for (int j = 0; j < num; ++j) {
                std::cout << i << j << std::endl;
            }
        }

        for (int i = 0; i < num; ++i) {
            std::cout << i << std::endl;
        }
    }

    int Bigo::addItems(int num) {
        return num + num;
    }

    void Bigo::printItems(int num1, int num2) {
        for (int i = 0; i < num1; ++i) {
            std::cout << i << std::endl;
        }

        for (int i = 0; i < num2; ++i) {
            std::cout << i << std::endl;
        }
    }


} // algoritmobigo