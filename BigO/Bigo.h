//
// Created by 72358 on 25/09/2024.
//

#ifndef DATA_ESTRUCTURE_C_BIGO_H
#define DATA_ESTRUCTURE_C_BIGO_H

namespace algoritmobigo {

    class Bigo {
    private:
        int num1;
        int num2;
    public:
        Bigo(int num1, int num2);

        int getNum1() const;

        void setNum1(int num1);

        int getNum2() const;

        void setNum2(int num2);

        static void printItemsOn(int num);

        static void dropConstant(int num);

        static void nExponent(int num);

        static void dropNonDomiant(int num);

        static int addItems(int num);

        static void printItems(int num1, int num2);

    };

} // algoritmobigo

#endif //DATA_ESTRUCTURE_C_BIGO_H
