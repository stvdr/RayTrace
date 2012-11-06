//
//  Point.h
//  RayTracer
//
//  Created by Steven Iannelli on 11/1/12.
//  Copyright (c) 2012 Steven Iannelli. All rights reserved.
//

#pragma once

#include "Vector.h"

using RayTracer::Vector3;

namespace RayTracer {
    
    template<typename T>
    class Point3 {
    public:
        T x, y, z;
        
        Point3<T>(T X, T Y, T Z) : x(X), y(Y), z(Z) { }
        
        Point3<T> operator+(const Vector3<T>& v) const {
            return Point3<T>(x+v.x, y+v.y, z+v.z);
        }
        
        Point3<T> operator-(const Vector3<T>& v) const {
            return Point3<T>(x-v.x, y-v.y, z-v.z);
        }
        
        Point3<T>& operator+=(const Vector3<T>& v){
            x+=v.x;
            y+=v.y;
            z+=v.z;
            
            return *this;
        }
        
        Point3<T>& operator-=(const Vector3<T>& v){
            x-=v.x;
            y-=v.y;
            z-=v.z;
            
            return *this;
        }
    };
}
