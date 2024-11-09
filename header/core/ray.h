#ifndef RAY_H
#define RAY_H

#include "vec3.h"

/*
    We can represent the idea of a ray as a class, and represent the function 𝐏(𝑡)
    as a function that we'll call ray::at(t):

    𝐏(𝑡)=𝐀+𝑡𝐛

    𝐏 is a 3D position along a line in 3D. 𝐀
    is the ray origin and 𝐛
    is the ray direction. The ray parameter 𝑡
    is a real number (double in the code). Plug in a different 𝑡
    and 𝐏(𝑡)
    moves the point along the ray. Add in negative 𝑡
    values and you can go anywhere on the 3D line. For positive 𝑡
    , you get only the parts in front of 𝐀
    , and this is what is often called a half-line or a ray

*/

class ray {
  public:
    ray() {}

    ray(const point3& origin, const vec3& direction) : orig(origin), dir(direction) {}

    const point3& origin() const  { return orig; }
    const vec3& direction() const { return dir; }

    point3 at(double t) const {
        return orig + t*dir;
    }

  private:
    point3 orig;
    vec3 dir;
};

#endif