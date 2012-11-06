//
//  Shape.h
//  RayTracer
//
//  Created by Steven Iannelli on 11/2/12.
//  Copyright (c) 2012 Steven Iannelli. All rights reserved.
//

#pragma once

#include "Ray.h"

namespace RayTracer{

template<typename T>
class Shape {
public:
    virtual bool CanIntersect()=0;
    virtual void Intersect(Ray3<T> ray) = 0;
};
    
}
