//#include <vector>
//#include <iostream>
//#include "Vec3.h"
//
//using Color = vec3;
//
//int write_image(std::vector<Color> img_data) {
//	int img_w = 256;
//	int img_h = 256;
//
//	std::cout << "P3\n" << img_w << ' ' << img_h << "\n255\n";
//
//	for (int j = 0; j < img_h; j++) {
//		std::clog << "\rScanlines remaining: " << (img_h - j) << ' ' << std::flush;
//		for (int i = 0; i < img_w; i++) {
//			auto r = img_data[i];
//			auto g = double(j) / (img_h - 1);
//			auto b = 0.0;
//
//			int out_r = int(255.99 * r);
//			int out_g = int(255.99 * g);
//			int out_b = int(255.99 * b);
//
//			std::cout << out_r << ' ' << out_g << ' ' << out_b << '\n';
//		}
//	}
//	std::clog << "\rComplete!\t" << std::flush;
//
//	return 0;
//}