//
// Created by 72358 on 1/10/2024.
//

#ifndef DATA_ESTRUCTURE_C_COOKIE_H
#define DATA_ESTRUCTURE_C_COOKIE_H

#include <string>

namespace cookieClass {

    using namespace std;

    class Cookie {

    private:
        string color;
        string taste;

    public:
        Cookie(string color, string taste);

        void mostrarGalleta();

        const string &getColor() const;

        void setColor(const string &color);

        const string &getTaste() const;

        void setTaste(const string &taste);
    };

} // cookieClass

#endif //DATA_ESTRUCTURE_C_COOKIE_H
