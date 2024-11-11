#include <iostream>
#include <vector>
#include <string>
// Include other headers that are unlikely to change
#include "utils/rtweekend.h"      // For utility constants and functions
#include "camera/camera.h"
#include "objects/hittable.h"
#include "objects/hittable_list.h"
#include "objects/sphere.h"

int main() {
    hittable_list world;

    world.add(make_shared<sphere>(point3(0,0,-1), 0.5));
    world.add(make_shared<sphere>(point3(0,-100.5,-1), 100));

    camera cam;

    cam.aspect_ratio        = 16.0 / 9.0;
    cam.image_width         = 400;
    cam.samples_per_pixel   = 100;    // increased from 100 to 300 
    cam.max_depth           = 50;

    cam.render(world);
}