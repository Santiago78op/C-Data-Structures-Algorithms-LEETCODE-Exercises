```c++
#include <iostream>

int main() {

    int* num1 = new int(11);
    int* num2 = num1;

    *num1 = 22;

    std::cout << "Numero 1: " << *num1 << std::endl;
    std::cout << "Numero 2: " << *num2 << std::endl;

    return 0;
}

#include <iostream>
#include "ClassAndPointers/Cookie.h"

using namespace std;

int main() {

    auto* cookieOne= new cookieClass::Cookie("Green","Chocolate");
    auto* cookieTwo= new cookieClass::Cookie("Red","Kiwi");

    cout << "Cookie 1: " << cookieOne->getColor() << endl;
    cout << "Cookie 2: " << cookieOne->getTaste() << endl;

    cookieTwo->setTaste("Apple");

    cout << "Cookie 1: " << cookieTwo->getColor() << endl;
    cout << "Cookie 2: " << cookieTwo->getTaste() << endl;

    return 0;
}

```