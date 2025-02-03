//
// Created by 72358 on 1/10/2024.
//

#include "Cookie.h"

#include <utility>
#include <iostream>

namespace cookieClass {

    using namespace std;

    Cookie::Cookie(string color, string taste) : color(std::move(color)), taste(std::move(taste)) {}

    const string &Cookie::getColor() const {
        return color;
    }

    void Cookie::setColor(const string &color) {
        Cookie::color = color;
    }

    const string &Cookie::getTaste() const {
        return taste;
    }

    void Cookie::setTaste(const string &taste) {
        Cookie::taste = taste;
    }

    void Cookie::mostrarGalleta() {
        cout << "Color: " << color << "Sabor: " << taste;
    }

} // cookieClass