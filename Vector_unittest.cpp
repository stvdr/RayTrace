//
//  Vector_unittest.cpp
//  RayTracer
//
//  Created by Steven Iannelli on 10/29/12.
//  Copyright (c) 2012 Steven Iannelli. All rights reserved.
//

#include "Vector.h"
#include "gtest/gtest.h"
#include <cmath>

using RayTracer::Vector3;
using std::sqrt;

#define VECTOR_EQ(a, b, c, v) \
    EXPECT_EQ(a, v.x); \
    EXPECT_EQ(b, v.y); \
    EXPECT_EQ(c, v.z)

TEST(VectorTest, Accessors){
    Vector3<float> v(1.0f, 2.0f, 3.0f);
    VECTOR_EQ(1.0f, 2.0f, 3.0f, v);
    
    EXPECT_EQ(1.0f, v.x);
    EXPECT_EQ(2.0f, v.y);
    EXPECT_EQ(3.0f, v.z);
}

TEST(VectorTest, Setters){
    Vector3<float> v;
    v.x = 1.0f;
    v.y = 2.0f;
    v.z = 3.0f;
    
    VECTOR_EQ(1.0f, 2.0f, 3.0f, v);
    
    Vector3<float> u = v = Vector3<float>(4.0f, 5.0f, 6.0f);
    VECTOR_EQ(4.0f, 5.0f, 6.0f, v);
    VECTOR_EQ(4.0f, 5.0f, 6.0f, u);
}

TEST(VectorTest, Constructor) {
    Vector3<float> v(1.0f, 1.0f, 1.0f);
    VECTOR_EQ(1.0f, 1.0f, 1.0f, v);
    
    Vector3<float> u;
    VECTOR_EQ(0.0f, 0.0f, 0.0f, u);
}

TEST(VectorTest, Copy){
    Vector3<float> v(2.0f, 3.0f, 4.0f);
    Vector3<float> u(v);
    
    VECTOR_EQ(2.0f, 3.0f, 4.0f, v);
    VECTOR_EQ(2.0f, 3.0f, 4.0f, u);
}

TEST(VectorTest, Addition){
    Vector3<float> v(1.0f, 12.0f, 32.0f);
    Vector3<float> u(3.0f, 5.0f, 80.0f);
    
    Vector3<float> add = v+u;
    VECTOR_EQ(4.0f, 17.0f, 112.0f, add);
    
    v+=v+=u;
    VECTOR_EQ(8.0f, 34.0f, 224.0f, v);
}

TEST(VectorTest, Subtraction){
    Vector3<float> v(4.0f, 17.0f, 112.0f);
    Vector3<float> u(3.0f, 5.0f, 80.0f);
    
    Vector3<float> subtract=v-u;
    VECTOR_EQ(1.0f, 12.0f, 32.0f, subtract);
    
    v-=v-=u;
    VECTOR_EQ(0.0f, 0.0f, 0.0f, v);
}

TEST(VectorTest, Negative){
    Vector3<float> v(1.0f, 2.0f, 3.0f);
    v = -v;
    VECTOR_EQ(-1.0f, -2.0f, -3.0f, v);
}

TEST(VectorTest, Scale){
    Vector3<float> v(1.0f, 2.0f, 3.0f);

    v = v*=5.0f;
    VECTOR_EQ(5.0f, 10.0f, 15.0f, v);
}

TEST(VectorTest, ScalarMultiply){
    Vector3<float> v(1.0f, 2.0f, 3.0f);
    Vector3<float> result = v*5;
    VECTOR_EQ(5.0f, 10.0f, 15.0f, result);
    
    Vector3<float> u(4.0f, 5.0f, 6.0f);
    result = 5.0*u;
    VECTOR_EQ(20.0f, 25.0f, 30.0f, result);
    
    v*=5;
    VECTOR_EQ(5.0f, 10.0f, 15.0f, v);
}

TEST(VectorTest, ScalarDivide){
    Vector3<float> v(1.0f, 2.0f, 6.0f);
    Vector3<float> result = v/2.0f;
    VECTOR_EQ(0.5f, 1.0f, 3.0f, result);
    
    v = v/=2.0f;
    VECTOR_EQ(0.5f, 1.0f, 3.0f, v);
}

TEST(VectorTest, Magnitude){
    //test default
    Vector3<double> v;
    EXPECT_EQ(0.0, v.Magnitude());
    
    v = Vector3<double>(1.0, 2.0, 3.0);
    EXPECT_EQ(sqrt(14.0), v.Magnitude());
    
    v.x = 10.0;
    EXPECT_EQ(sqrt(113.0), v.Magnitude());
    
    v.y = 5;
    EXPECT_EQ(sqrt(134.0), v.Magnitude());
    
    v.z = 8;
    EXPECT_EQ(sqrt(189.0), v.Magnitude());
}

TEST(VectorTest, DotProduct){
    Vector3<float> v(2.0f, 4.0f, 8.0f);
    Vector3<float> u(3.0f, 6.0f, 9.0f);
    EXPECT_EQ(102.0f, v.Dot(u));
}

TEST(VectorTest, Equality){
    Vector3<float> a(1.0f, 2.0f, 3.0f);
    Vector3<float> b(1.0f, 2.0f, 3.0f);
    Vector3<float> c(4.0f, 5.0f, 6.0f);
    
    EXPECT_TRUE(a==b);
    EXPECT_FALSE(a==c);
    EXPECT_FALSE(a!=b);
    EXPECT_TRUE(a!=c);
}

TEST(VectorTest, Normalize){
    Vector3<float> v(1.0f, 0.0f, 1.0f);
    v.Normalize();
    VECTOR_EQ(1.0f/sqrt(2.0f), 0, 1.0f/sqrt(2.0f), v);
}