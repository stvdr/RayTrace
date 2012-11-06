//
//  gtest_main.cpp
//  RayTracer
//
//  Created by Steven Iannelli on 10/29/12.
//  Copyright (c) 2012 Steven Iannelli. All rights reserved.
//

#include <stdio.h>

#include "gtest/gtest.h"

GTEST_API_ int main(int argc, char **argv) {
    printf("Running main() from gtest_main.cc\n");
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}