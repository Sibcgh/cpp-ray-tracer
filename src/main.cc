#include <iostream>
#include <vector>
#include <string>
// Include other headers that are unlikely to change
#include "utils/rtweekend.h"      // For utility constants and functions
#include "camera/camera.h"
#include "objects/hittable.h"
#include "objects/hittable_list.h"
#include "objects/sphere.h"
#include "objects/tetrahedron.h"
#include "objects/cube.h"
#include "objects/material.h"


int main() {
    hittable_list world;

    // Define materials
    auto material_ground = make_shared<lambertian>(color(0.2, 0.8, 0.2));
    auto material_center = make_shared<lambertian>(color(0.1, 0.2, 0.5));
    auto material_left   = make_shared<dielectric>(1.50);
    auto material_bubble = make_shared<dielectric>(1.00 / 1.50);
    auto material_right  = make_shared<metal>(color(0.8, 0.6, 0.2), 1.0);
    auto material_cube = make_shared<metal>(color(0.95, 0.64, 0.54), 1.0);  // Copper-like color and slight roughness
    auto material_tetra = make_shared<metal>(color(0.9, 0.2, 0.2), 0.8);  // Red metal with slight roughness

    // Add spheres
    world.add(make_shared<sphere>(point3( 0.0, -100.5, -1.0), 100.0, material_ground));
    world.add(make_shared<sphere>(point3( 0.0,    0.0, -1.2),   0.5, material_center));
    world.add(make_shared<sphere>(point3(-1.0,    0.0, -1.0),   0.5, material_left));
    world.add(make_shared<sphere>(point3(-1.0,    0.0, -1.0),   0.4, material_bubble));
    world.add(make_shared<sphere>(point3( 1.0,    0.0, -1.0),   0.5, material_right));

    // Add a floating cube
    world.add(std::make_shared<cube>(point3(-0.5, 0.5, -2.8), 1.0, material_cube));

    // Add a tetrahedron
    world.add(std::make_shared<tetrahedron>(
        point3(1.5, 0.0, -2.5),  // Base vertex
        point3(2.0, 0.0, -2.0),  // Second base vertex
        point3(1.5, 0.0, -3.0),  // Third base vertex
        point3(1.7, 1.0, -2.5),  // Apex vertex
        material_tetra
    ));

    // Setup camera
    camera cam;

    cam.aspect_ratio      = 16.0 / 9.0;
    cam.image_width       = 400;
    cam.samples_per_pixel = 500;
    cam.max_depth         = 50;

    cam.vfov     = 50;
    cam.lookfrom = point3(-2, 2, 3);  // Position the camera
    cam.lookat   = point3(0.0, 0.5, 0.0);  // Look towards the center of the scene
    cam.vup      = vec3(0, 1, 0);        // Camera 'up' direction

    // Render the scene
    cam.render(world);

    return 0;
}