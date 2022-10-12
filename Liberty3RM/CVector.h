#pragma once

#include <math.h>

class CVector {
public:
	float x, y, z;
	
	static double getDistanceBetween2Points(CVector first, CVector second);
};