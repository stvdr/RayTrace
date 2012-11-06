//
//  Point_unittest.cpp
//  RayTracer
//
//  Created by Steven Iannelli on 11/1/12.
//  Copyright (c) 2012 Steven Iannelli. All rights reserved.
//


#include "Point.h"
#include "gtest/gtest.h"

using RayTracer::Point3;

#define POINT_EQ(a, b, c, p) \
EXPECT_EQ(a, p.x); \
EXPECT_EQ(b, p.y); \
EXPECT_EQ(c, p.z)

TEST(PointTest, Construct){
    Point3<float> p = { 1.0f, 2.0f, 3.0f };
    
    POINT_EQ(1.0f, 2.0f, 3.0f, p);
}

TEST(PointTest, Plus){
    Point3<float> p = {1.0f, 2.0f, 3.0f};
    Vector3<float> v = {10.0f, 20.0f, 30.0f};
    
    Point3<float> r = p + v;
    POINT_EQ(11.0f, 22.0f, 33.0f, r);
}

TEST(PointTest, Minus){
    Point3<float> p = {1.0f, 2.0f, 3.0f};
    Vector3<float> v = {10.0f, 20.0f, 30.0f};
    
    Point3<float> r = p - v;
    POINT_EQ(-9.0f, -18.0f, -27.0f, r);
}

TEST(PointTest, PlusEquals){
    Point3<float> p = {1.0f, 2.0f, 3.0f};
    Vector3<float> v = {10.0f, 20.0f, 30.0f};
    
    (p+=v)+=v;
    POINT_EQ(21.0f, 42.0f, 63.0f, p);
}

TEST(PointTest, MinusEquals){
    Point3<float> p = {1.0f, 2.0f, 3.0f};
    Vector3<float> v = {10.0f, 20.0f, 30.0f};
    
    (p-=v)-=v;
    POINT_EQ(-19.0f, -38.0f, -57.0f, p);
}