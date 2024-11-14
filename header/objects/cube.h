#ifndef CUBE_H
#define CUBE_H

#include "hittable.h"

class cube : public hittable {
  public:
    cube(const point3& center, double side_length, shared_ptr<material> mat)
        : mat(mat) {
        double half_side = side_length / 2.0;
        min_corner = center - vec3(half_side, half_side, half_side);
        max_corner = center + vec3(half_side, half_side, half_side);
    }

    bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
        auto t_min = ray_t.min;
        auto t_max = ray_t.max;
        vec3 normal;  // Normal corresponding to the hit face.

        for (int i = 0; i < 3; ++i) {
            auto inv_dir = 1.0 / r.direction()[i];
            auto t0 = (min_corner[i] - r.origin()[i]) * inv_dir;
            auto t1 = (max_corner[i] - r.origin()[i]) * inv_dir;

            if (inv_dir < 0.0) std::swap(t0, t1);

            if (t0 > t_min) {
                t_min = t0;
                normal = vec3(0, 0, 0);
                normal[i] = inv_dir > 0 ? -1 : 1;  // Face normal direction.
            }

            if (t1 < t_max) {
                t_max = t1;
            }

            if (t_min > t_max) return false;
        }

        rec.t = t_min;
        rec.p = r.at(rec.t);
        rec.normal = normal;
        rec.set_face_normal(r, rec.normal);
        rec.mat = mat;

        return true;
    }

  private:
    point3 min_corner;
    point3 max_corner;
    shared_ptr<material> mat;
};

#endif
