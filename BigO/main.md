```c++
#include <iostream>
#include "BigO/Bigo.h"

int main() {
    algoritmobigo::Bigo bigo(10,20);

    std::cout << "Num1: " << bigo.getNum1() << std::endl;
    std::cout << "Num2: " << bigo.getNum2() << std::endl;

    bigo.setNum1(5);
    bigo.setNum2(10);

    std::cout << "Num1 MD: " << bigo.getNum1() << std::endl;
    std::cout << "Num2 MD: " << bigo.getNum2() << std::endl;

    algoritmobigo::Bigo::printItemsOn(5);

    return 0;
}
```