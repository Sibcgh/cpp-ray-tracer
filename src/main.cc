#include <iostream>
#include <vector>
#include <string>
#include "utils/rtweekend.h"      // For utility constants and functions
#include "camera/camera.h"
#include "objects/hittable.h"
#include "objects/hittable_list.h"
#include "objects/sphere.h"
#include "objects/tetrahedron.h"
#include "objects/cube.h"
#include "objects/material.h"

// Function declarations for each scene
void scene1(hittable_list& world, camera& cam);
void scene2(hittable_list& world, camera& cam);
void scene3(hittable_list& world, camera& cam);



int main() {
    hittable_list world;
    camera cam;

    // Call the desired scene
    scene1(world, cam);  // Call scene1
    // scene2(world, cam); // Uncomment to test scene2
    //scene3(world, cam); // Uncomment to test scene3

    // Render the scene
    cam.render(world);

    return 0;
}


void scene1(hittable_list& world, camera& cam) {
    // Define materials
    auto material_ground = make_shared<lambertian>(color(0.2, 0.8, 0.2));
    auto material_left   = make_shared<metal>(color(0.8, 0.6, 0.2), 0.3);
    auto material_center = make_shared<emissive>(color(4.0, 2.0, 2.0));
    auto material_right  = make_shared<dielectric>(1.5);

    // Add spheres
    world.add(make_shared<sphere>(point3( 0.0, -100.5, -1.0), 100.0, material_ground));
    world.add(make_shared<sphere>(point3( 0.0,    0.0, -1.0),   0.5, material_center));
    world.add(make_shared<sphere>(point3(-1.0,    0.0, -1.0),   0.5, material_left));
    world.add(make_shared<sphere>(point3( 1.0,    0.0, -1.0),   0.5, material_right));

    // Setup camera
    cam.aspect_ratio      = 16.0 / 9.0;
    cam.image_width       = 400;
    cam.samples_per_pixel = 100;
    cam.max_depth         = 50;

    cam.vfov     = 30;
    cam.lookfrom = point3(-2,2,1);
    cam.lookat   = point3(0,0,-1);
    cam.vup      = vec3(0,1,0);

    cam.defocus_angle = 10.0;
    cam.focus_dist    = 3.4;
}

void scene2(hittable_list& world, camera& cam) {
    // Define materials
    auto material_ground = make_shared<lambertian>(color(0.2, 0.8, 0.2));
    auto material_center = make_shared<lambertian>(color(0.1, 0.2, 0.5));
    auto material_left   = make_shared<dielectric>(1.50);
    auto material_bubble = make_shared<dielectric>(1.00 / 1.50);
    auto material_right  = make_shared<metal>(color(0.8, 0.6, 0.2), 1.0);
    auto material_cube = make_shared<metal>(color(0.95, 0.64, 0.54), 1.0);  
    auto material_tetra = make_shared<metal>(color(0.9, 0.2, 0.2), 0.8);

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
        point3(1.5, 0.0, -2.5),
        point3(2.0, 0.0, -2.0),
        point3(1.5, 0.0, -3.0),
        point3(1.7, 1.0, -2.5),
        material_tetra
    ));

    // Setup camera
    cam.aspect_ratio      = 16.0 / 9.0;
    cam.image_width       = 400;
    cam.samples_per_pixel = 100;
    cam.max_depth         = 50;

    cam.vfov     = 30;
    cam.lookfrom = point3(-2,2,1);
    cam.lookat   = point3(0,0,-1);
    cam.vup      = vec3(0,1,0);

    cam.defocus_angle = 10.0;
    cam.focus_dist    = 3.4;
}


void scene3(hittable_list& world, camera& cam) {
    // No need to declare `world` and `cam` again, they are already passed by reference.

    auto ground_material = make_shared<lambertian>(color(0.5, 0.5, 0.5));
    world.add(make_shared<sphere>(point3(0,-1000,0), 1000, ground_material));

    for (int a = -11; a < 11; a++) {
        for (int b = -11; b < 11; b++) {
            auto choose_mat = random_double();
            point3 center(a + 0.9*random_double(), 0.2, b + 0.9*random_double());

            if ((center - point3(4, 0.2, 0)).length() > 0.9) {
                shared_ptr<material> sphere_material;

                if (choose_mat < 0.8) {
                    auto albedo = color::random() * color::random();
                    sphere_material = make_shared<lambertian>(albedo);
                    auto center2 = center + vec3(0, random_double(0,.5), 0);
                    world.add(make_shared<sphere>(center, center2, 0.2, sphere_material));
                } else if (choose_mat < 0.95) {
                    auto albedo = color::random(0.5, 1);
                    auto fuzz = random_double(0, 0.5);
                    sphere_material = make_shared<metal>(albedo, fuzz);
                    world.add(make_shared<sphere>(center, 0.2, sphere_material));
                } else {
                    sphere_material = make_shared<dielectric>(1.5);
                    world.add(make_shared<sphere>(center, 0.2, sphere_material));
                }
            }
        }
    }

    auto material1 = make_shared<dielectric>(1.5);
    world.add(make_shared<sphere>(point3(0, 1, 0), 1.0, material1));

    auto material2 = make_shared<lambertian>(color(0.4, 0.2, 0.1));
    world.add(make_shared<sphere>(point3(-4, 1, 0), 1.0, material2));

    auto material3 = make_shared<metal>(color(0.7, 0.6, 0.5), 0.0);
    world.add(make_shared<sphere>(point3(4, 1, 0), 1.0, material3));

    // Camera setup
    cam.aspect_ratio      = 16.0 / 9.0;
    cam.image_width       = 400;
    cam.samples_per_pixel = 100;
    cam.max_depth         = 50;

    cam.vfov     = 20;
    cam.lookfrom = point3(13,2,3);
    cam.lookat   = point3(0,0,0);
    cam.vup      = vec3(0,1,0);

    cam.defocus_angle = 0.6;
    cam.focus_dist    = 10.0;
}