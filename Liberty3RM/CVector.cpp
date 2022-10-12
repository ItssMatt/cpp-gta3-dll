#include "CVector.h"

double CVector::getDistanceBetween2Points(CVector first, CVector second) {
	return sqrt(pow(first.x-second.x,2) + pow(first.y - second.y, 2) + pow(first.z - second.z, 2));
}