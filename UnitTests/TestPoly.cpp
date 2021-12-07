//
// Created by Екатерина on 16.11.2021.
//

#include "TestPoly.h"
bool test_01()
{
    Poly p1(2);
    Poly p2(2);
    p1.at(0, 0, 0) = 1;
    p1.at(1, 0, 0) = 2;
    p2.at(0, 0, 0) = 3;
    p2.at(0, 1, 0) = 4;
    p2.at(1, 0, 0) = 5;
    p2.at(0, 0, 1) = 5;
    Poly p3 = p1 + p2;
    return p3.getElem(0, 0, 0) == 4 &&
           p3.getElem(1, 0, 0) == 7 &&
           p3.getElem(0, 1, 0) == 4 &&
           p3.getElem(0, 0, 1) == 5;
}
bool test_02()
{
    Poly p1(2);
    Poly p2(2);
    p1.at(0, 0, 0) = 1;
    p1.at(1, 0, 0) = 2;
    p2.at(0, 0, 0) = 3;
    p2.at(0, 1, 0) = 4;
    p2.at(1, 0, 0) = 5;
    p2.at(0, 0, 1) = 5;
    Poly p3 = p1 * p2;
    return p3.at(0, 0, 0) == 3 &&
    p3.at(0, 1, 0) == 4 &&
    p3.at(1, 0, 0) == 11 &&
    p3.at(0, 0, 1) == 5 &&
            p3.at(1, 1, 0) == 8 &&
            p3.at(2, 0, 0) == 10 &&
            p3.at(1, 0, 1) == 10;
}
bool test_03()
{
    Poly p1(2);
    Poly p2(2);
    p1.at(0, 0, 0) = 1;
    p1.at(1, 0, 0) = 2;
    p1.at(0, 0, 1) = 1;// 2x + z + 1

    p2.at(0, 0, 0) = 3;
    p2.at(0, 1, 0) = 4;
    p2.at(1, 0, 0) = 5;
    p2.at(0, 0, 1) = 5;// 5x + 5z +4y + 3

    Poly p3 = p2.insertCopy(p1, p1, p1);
    return p3.at(0, 0, 0) == 17 &&
                  p3.at(0, 0, 1) == 14 &&
                  p3.at(1, 0, 0) == 28;

}
bool test_04()
{
    Poly p2(3);
    p2.at(0, 0, 0) = 3;
    p2.at(1, 1, 0) = 2;
    p2.at(1, 0, 0) = 4;
    p2.at(2, 0, 0) = 5;
    p2.at(2, 0, 1) = 6;
    Poly p3 = p2.derX();
    return p3.at(0, 1, 0) == 2 &&
           p3.at(0, 0, 0) == 4 &&
           p3.at(1, 0, 0) == 10 &&
           p3.at(1, 0, 1) == 12;
}
bool test_05()
{
    Poly p2(3);
    p2.at(0, 0, 0) = 3;
    p2.at(1, 1, 0) = 2;
    p2.at(0, 1, 0) = 4;
    p2.at(0, 2, 0) = 5;
    p2.at(0, 2, 1) = 6;
    Poly p3 = p2.derY();
    return p3.at(1, 0, 0) == 2 &&
           p3.at(0, 0, 0) == 4 &&
           p3.at(0, 1, 0) == 10 &&
           p3.at(0, 1, 1) == 12;
}
bool test_06()
{
    Poly p2(3);
    p2.at(0, 0, 0) = 3;
    p2.at(1, 0, 1) = 2;
    p2.at(0, 0, 1) = 4;
    p2.at(0, 0, 2) = 5;
    p2.at(0, 1, 2) = 6;
    Poly p3 = p2.derZ();
    return p3.at(1, 0, 0) == 2 &&
           p3.at(0, 0, 0) == 4 &&
           p3.at(0, 0, 1) == 10 &&
           p3.at(0, 1, 1) == 12;
}
bool test_07()
{
    Poly p1(3);
    Poly p2(3);
    p1.at(0, 0, 0) = 1;
    p1.at(0, 1, 0) = 2;
    p1.at(1, 1, 1) = 2;
    p1.at(1, 2, 2) = 4;

    p2.at(0, 0, 0) = 3;
    p2.at(0, 1, 0) = 2;
    p2.at(1, 0, 0) = 3;
    p2.at(2, 0, 1) = 5;
    p2.at(1, 2, 2) = 8;
    Poly p3 = p1 + p2;
    return p3.getElem(0, 0, 0) == 4 &&
           p3.getElem(0, 1, 0) == 4 &&
           p3.getElem(1, 1, 1) == 2 &&
           p3.getElem(1, 0, 0) == 3 &&
           p3.getElem(2, 0, 1) == 5 &&
           p3.getElem(1, 2, 2) == 12;
}
bool test_08()
{
    Poly p1(3);
    Poly p2(3);
    p1.at(0, 0, 0) = 1;
    p1.at(0, 1, 0) = 2;
    p1.at(1, 0, 1) = 3;

    p2.at(0, 0, 0) = 3;
    p2.at(0, 1, 0) = 2;
    p2.at(1, 0, 0) = 3;
    p2.at(2, 0, 1) = 5;
    Poly p3 = p1 * p2;
    return p3.at(0, 0, 0) == 3 &&
            p3.at(0, 1, 0) == 8 &&
            p3.at(1, 0, 0) == 3 &&
            p3.at(2, 0, 1) == 14 &&

            p3.at(0, 2, 0) == 4 &&
            p3.at(1, 1, 0) == 6 &&
            p3.at(2, 1, 1) == 10 &&

            p3.at(1, 0, 1) == 9 &&
            p3.at(1, 1, 1) == 6 &&
            p3.at(3, 0, 2) == 15;
}
bool test_09()
{
    Poly p11(2), p12(2), p13(2);
    Poly p2(2);
    p11.at(0, 0, 0) = 1;
    p11.at(1, 0, 0) = 2;
    p11.at(0, 0, 1) = 1;// 2x + z + 1

    p12.at(0, 0, 0) = 3;
    p12.at(1, 1, 0) = 2;
    p12.at(0, 1, 1) = 1;// 2xy + yz + 3

    p13.at(0, 0, 1) = 2;
    p13.at(1, 0, 1) = 4;
    p13.at(1, 1, 1) = 2;// 2xyz + 4xz + 2z

    p2.at(0, 0, 0) = 3;
    p2.at(0, 1, 0) = 4;
    p2.at(1, 0, 0) = 5;
    p2.at(0, 0, 1) = 5;
    p2.at(1, 0, 1) = 1; // 5x + 5z +4y + xz + 3

    Poly p3 = p2.insertCopy(p11, p12, p13);
    return p3.at(0, 0, 0) == 20 &&
           p3.at(1, 0, 0) == 10 &&
           p3.at(0, 0, 1) == 17 &&
           p3.at(1, 0, 1) == 28 &&
           p3.at(1, 1, 1) == 12 &&
           p3.at(1, 1, 0) == 8 &&
           p3.at(0, 1, 1) == 4 &&

           p3.at(0, 0, 2) == 2 &&
           p3.at(1, 0, 2) == 4 &&
           p3.at(1, 1, 2) == 2 &&

           p3.at(2, 0, 1) == 8 &&
           p3.at(2, 1, 1) == 4;

}
TestPoly::TestPoly()
{
    tests.push_back(test_01);
    tests.push_back(test_02);
    tests.push_back(test_03);
    tests.push_back(test_04);
    tests.push_back(test_05);
    tests.push_back(test_06);
    tests.push_back(test_07);
    tests.push_back(test_08);
    tests.push_back(test_09);
}

int TestPoly::testAll()
{
    for (int i = 0; i < tests.size(); i++)
        if (!(tests[i]()))
            return i;
    return -1;
}