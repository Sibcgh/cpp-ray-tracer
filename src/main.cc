#include <iostream>
#include <vector>
#include <string>
// Include other headers that are unlikely to change
#include "utils/rtweekend.h"      // For utility constants and functions
#include "camera/camera.h"
#include "objects/hittable.h"
#include "objects/hittable_list.h"
#include "objects/sphere.h"

// ray_color and main function as before

color ray_color(const ray& r, const hittable& world) {
    hit_record rec;
    if (world.hit(r, interval(0, infinity), rec)) {
        return 0.5 * (rec.normal + color(1,1,1));
    }

    vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5*(unit_direction.y() + 1.0);
    return (1.0-a)*color(1.0, 1.0, 1.0) + a*color(0.5, 0.7, 1.0);
}

int main() {
    hittable_list world;

    world.add(make_shared<sphere>(point3(0,0,-1), 0.5));
    world.add(make_shared<sphere>(point3(0,-100.5,-1), 100));

    camera cam;

    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width  = 400;
    cam.samples_per_pixel = 300;    // increased from 100 to 300 


    cam.render(world);
}