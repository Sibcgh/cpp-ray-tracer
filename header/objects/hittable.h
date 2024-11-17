#ifndef HITTABLE_H
#define HITTABLE_H

#include "utils/rtweekend.h"  // Includes vec3, ray, and utility functions

class material;

class hit_record {
public:
    point3 p;
    vec3 normal;
    shared_ptr<material> mat; // material pointer (use 'mat' instead of 'material_ptr')
    double t;
    double u;
    double v;
    bool front_face;

    void set_face_normal(const ray& r, const vec3& outward_normal) {
        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }
};

class hittable {
public:
    virtual ~hittable() = default;

    virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const = 0; // Use 'interval ray_t' here
};

#endif
