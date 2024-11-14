#ifndef TETRAHEDRON_H
#define TETRAHEDRON_H

#include "hittable.h"

class tetrahedron : public hittable {
public:
    point3 v0, v1, v2, v3;  // Vertices of the tetrahedron
    std::shared_ptr<material> mat_ptr;

    tetrahedron(point3 vertex0, point3 vertex1, point3 vertex2, point3 vertex3, std::shared_ptr<material> m)
        : v0(vertex0), v1(vertex1), v2(vertex2), v3(vertex3), mat_ptr(m) {}

    bool ray_intersect_triangle(const ray& r, const point3& v0, const point3& v1, const point3& v2, interval ray_t, hit_record& rec) const {
        // Edges of the triangle
        vec3 edge1 = v1 - v0;
        vec3 edge2 = v2 - v0;

        // Calculate the determinant (denoted as "a" in Möller-Trumbore)
        vec3 h = cross(r.direction(), edge2);
        double a = dot(edge1, h);

        if (a > -1e-8 && a < 1e-8) {
            return false;  // Ray is parallel to the triangle
        }

        double f = 1.0 / a;
        vec3 s = r.origin() - v0;
        double u = f * dot(s, h);

        if (u < 0.0 || u > 1.0) {
            return false;  // Intersection outside of triangle
        }

        vec3 q = cross(s, edge1);
        double v = f * dot(r.direction(), q);

        if (v < 0.0 || u + v > 1.0) {
            return false;  // Intersection outside of triangle
        }

        // Calculate t (the point of intersection)
        double t = f * dot(edge2, q);

        if (t > ray_t.min && t < ray_t.max) {
            rec.t = t;
            rec.p = r.at(t);
            rec.normal = cross(edge1, edge2); // Normal of the triangle
            rec.mat = mat_ptr;
            return true;
        }

        return false;
    }

    virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
        bool hit_anything = false;
        hit_record temp_rec;

        // Check intersection with each of the four faces of the tetrahedron (4 triangles)
        hit_anything |= ray_intersect_triangle(r, v0, v1, v2, ray_t, temp_rec);
        if (hit_anything) {
            ray_t.max = temp_rec.t;  // Update ray_t.max for closer intersection
            rec = temp_rec;
        }

        hit_anything |= ray_intersect_triangle(r, v0, v1, v3, ray_t, temp_rec);
        if (hit_anything) {
            ray_t.max = temp_rec.t;
            rec = temp_rec;
        }

        hit_anything |= ray_intersect_triangle(r, v1, v2, v3, ray_t, temp_rec);
        if (hit_anything) {
            ray_t.max = temp_rec.t;
            rec = temp_rec;
        }

        hit_anything |= ray_intersect_triangle(r, v2, v0, v3, ray_t, temp_rec);
        if (hit_anything) {
            ray_t.max = temp_rec.t;
            rec = temp_rec;
        }

        return hit_anything;
    }
};

#endif
