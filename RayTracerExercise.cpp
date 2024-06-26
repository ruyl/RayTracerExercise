// RayTracerExercise.cpp : Defines the entry point for the application.
//

#include "RayTracerExercise.h"

#include "color.h"
#include "vec3.h"

#include <iostream>

int main()
{
	int img_w = 256;
	int img_h = 256;

	std::cout << "P3\n" << img_w << ' ' << img_h << "\n255\n";

	for (int j = 0; j < img_h; j++) {
		std::clog << "\rScanlines remaining: " << (img_h - j) << ' ' << std::flush;
		
		for (int i = 0; i < img_w; i++) {
			color pixel_color = {
				double(i) / (img_w - 1),
				double(j) / (img_h - 1),
				0.0
			};
			write_color(std::cout, pixel_color);
		}
	}
	std::clog << "\rComplete!\t" << std::flush;

	return 0;
}
