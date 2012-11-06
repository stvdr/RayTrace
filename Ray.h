//
//  Ray.h
//  RayTracer
//
//  Created by Steven Iannelli on 11/2/12.
//  Copyright (c) 2012 Steven Iannelli. All rights reserved.
//

#pragma once

#include "Point.h"
#include "Vector.h"

namespace RayTracer {
    template<typename T>
    class Ray3 {
    public:
        Point3<T> Origin;
        Vector3<T> Direction;
        
        Ray3<T>(const Point3<T> &origin, const Vector3<T> &direction)
            : Origin(origin), Direction(direction) { }
        
        Point3<T> operator()(double t) const {
            return Origin + t*Direction;
        }
    };
}