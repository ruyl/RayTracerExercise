// RayTracerExercise.cpp : Defines the entry point for the application.
//

#include "RayTracerExercise.h"

#include "color.h"
#include "vec3.h"
#include "ray.h"

#include <iostream>

color ray_color(const ray& r) {
	auto unit_dir = unit_vector(r.direction());
	auto a = .5 * (unit_dir.y() + 1.0);
	auto blue_blend_over_y = (1 - a) * color(1.0, 1.0, 1.0) + a * color(.5, .7, 1.0) * 1;
	return blue_blend_over_y;
}

int main()
{
	auto aspect_ratio = 16.0 / 9.0;
	int img_w = 400;

	int img_h = (int) (img_w / aspect_ratio);
	img_h = (img_h < 1) ? 1 : img_h;

	auto focal_length = 1.0;
	auto viewport_height = 2.0;
	// this can be less than one due to being a double; also we use the "true" aspect ratio, not the ideal one here
	auto viewport_width = viewport_height * ((double)img_w / img_h);
	auto camera_center = point3(0, 0, 0);

	// convention calls this u(?)
	auto viewport_right = vec3(viewport_width, 0, 0);
	auto viewport_down = vec3(0, viewport_height, 0);

	auto viewport_h_p_space = viewport_right / img_w;
	auto viewport_v_p_space = viewport_down / img_h;

	// remember - the focal length is negative because the direction from the camera to the viewport is the negative z direction
	auto viewport_topleft = camera_center - vec3(0, 0, focal_length) - viewport_right / 2 - viewport_down / 2;
	auto pixel_0 = viewport_topleft + ((viewport_h_p_space + viewport_v_p_space) / 2);

	std::cout << "P3\n" << img_w << ' ' << img_h << "\n255\n";

	for (int j = 0; j < img_h; j++) {
		std::clog << "\rScanlines remaining: " << (img_h - j) << ' ' << std::flush;
		
		for (int i = 0; i < img_w; i++) {
			auto pixel_center = pixel_0 + (viewport_h_p_space * i) + (viewport_v_p_space * j);
			auto view_ray_dir = camera_center - pixel_center;

			auto color_to_draw = ray_color(ray(camera_center, view_ray_dir));
			write_color(std::cout, color_to_draw);
		}
	}
	std::clog << "\rComplete!                       \n" << std::flush;

	return 0;
}