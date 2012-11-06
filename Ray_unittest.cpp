//
//  Ray_unittest.cpp
//  RayTracer
//
//  Created by Steven Iannelli on 11/2/12.
//  Copyright (c) 2012 Steven Iannelli. All rights reserved.
//

#include "Ray.h"
#include "gtest/gtest.h"

using namespace RayTracer;

#define VECTOR_EQ(a, b, c, v) \
EXPECT_EQ(a, v.x); \
EXPECT_EQ(b, v.y); \
EXPECT_EQ(c, v.z)

#define POINT_EQ(a, b, c, p) \
EXPECT_EQ(a, p.x); \
EXPECT_EQ(b, p.y); \
EXPECT_EQ(c, p.z)

TEST(RayTests, T){
    Ray3<float> r(Point3<float>(0.0f, 0.0f, 0.0f),
                  Vector3<float>(1.0f, 1.0f, 1.0f));
    
    VECTOR_EQ(1.0f, 1.0f, 1.0f, r.Direction);
    POINT_EQ(0.0f, 0.0f, 0.0f, r.Origin);
    
    Point3<float> p = r(0.5f);
    POINT_EQ(0.5f, 0.5f, 0.5f, p);
    p = r(0.3f);
    POINT_EQ(0.3f, 0.3f, 0.3f, p);
}