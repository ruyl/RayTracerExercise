#pragma once
#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

#include <iostream>

using color = vec3;

void write_color(std::ostream& outstream, const color& pixel_color)
{
	auto r = pixel_color.x();
	auto g = pixel_color.y();
	auto b = pixel_color.z();

	int out_r = int(255.99 * r);
	int out_g = int(255.99 * g);
	int out_b = int(255.99 * b);

	std::cout << out_r << ' ' << out_g << ' ' << out_b << '\n';
}

#endif // !COLOR_H

