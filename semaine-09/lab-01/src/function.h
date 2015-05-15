#ifndef FUNCTION_H
#define FUNCTION_H

#include "Point.h"

/*
 * Entrée: les deux points à comparer
 * Sortie: un bool
 *
 * Cette fonction compare deux points pour savoir s'ils sont équivalents.
 */
bool is_same_point(Point &p1, Point &p2);

/*
 * Entrée: un angle en radian
 * Sortie: un angle en degré
 *
 * Cette fonction convertit un angle de radian à degré.
 */
double rad_to_deg(double rad);

#endif
