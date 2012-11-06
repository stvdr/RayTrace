//
//  Vector.h
//  RayTracer
//
//  Created by Steven Iannelli on 10/29/12.
//  Copyright (c) 2012 Steven Iannelli. All rights reserved.
//

#pragma once

#include <cmath>

using std::sqrt;

namespace RayTracer
{
    
template<typename T>
class Vector3 {
public:
    T x, y, z;
    
    Vector3<T>& Set(const T X, const T Y, const T Z) {
        x = X;
        y = Y;
        z = Z;
        return *this;
    }
    
    Vector3<T>() : Vector3::Vector3<T>(0,0,0) { }
    
    Vector3<T>(const T X, const T Y, const T Z) : x(X), y(Y), z(Z) { }
    
    Vector3<T>(const Vector3<T>& copy) {
        Set(copy.x, copy.y, copy.z);
    }
    
    Vector3<T>& operator=(const Vector3<T>& u) {
        return Set(u.x, u.y, u.z);
    }
    
    Vector3<T> operator+(const Vector3<T>& u) const {
        return Vector3<T>(x + u.x,
                          y + u.y,
                          z + u.z);
    }
    
    Vector3<T> operator-(const Vector3<T>& u) const {
        return Vector3<T>(x - u.x,
                          y - u.y,
                          z - u.z);
    }
    
    Vector3<T> operator-() const {
        return Vector3<T>(-x, -y, -z);
    }
    
    Vector3<T> operator*(const T scalar) const {
        return Vector3<T>(x * scalar,
                          y * scalar,
                          z * scalar);
    }
    
    Vector3<T> operator/(const T scalar) const {
        return Vector3<T>(x / scalar,
                          y / scalar,
                          z / scalar);
    }
    
    Vector3<T>& operator*=(const T scalar) {
        x*=scalar;
        y*=scalar;
        z*=scalar;
        
        return *this;
    }
    
    Vector3<T>& operator/=(const T scalar) {
        x/=scalar;
        y/=scalar;
        z/=scalar;
        
        return *this;
    }
    
    Vector3<T>& operator+=(const Vector3<T>& a) {
        x += a.x;
        y += a.y;
        z += a.z;
        
        return *this;
    }
    
    Vector3<T>& operator-=(const Vector3<T>& s) {
        x -= s.x;
        y -= s.y;
        z -= s.z;

        return *this;
    }
    
    bool operator==(const Vector3<T>& v) const {
        return x==v.x && y==v.y && z==v.z;
    }
    
    bool operator!=(const Vector3<T>& v) const {
        return !(*this==v);
    }
    
    T Dot(const Vector3<T>& v) const {
        return x*v.x + y*v.y + z*v.z;
    }
    
    /*Vector3<T> Cross(const Vector3<T>& u, const Vector3<T>& v) const{
        
    }*/
    
    double Magnitude() const {
        return sqrt(MagnitudeSquared());
    }
    
    double MagnitudeSquared() const {
        return x*x + y*y + z*z;
    }
    
    //scale to magnitude 1
    void Normalize() {
        (*this)*=(1.0/Magnitude());
    }
    
    //friends
    template<typename F> friend Vector3<T> operator*(F scalar, const Vector3<T>& v){
        return Vector3<T>(scalar * v.x,
                          scalar * v.y,
                          scalar * v.z);
    }
};
    
} //namespace Vector
