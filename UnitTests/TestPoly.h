//
// Created by Екатерина on 16.11.2021.
//

#ifndef VIEW_CPP_TESTPOLY_H
#define VIEW_CPP_TESTPOLY_H
#include "../Primitives/Surfaces/Poly.h"
typedef bool (*test)();
class TestPoly{
public:
    TestPoly();
    int testAll();

private:
    std::vector<test> tests;
};


#endif //VIEW_CPP_TESTPOLY_H
