#include "Point.h"

Point::Point(const Point& p)
{
  x = p.x;
  y = p.y;
}


Point& Point::operator=(const Point& p) {
  if (&p == this) return *this;
  x = p.x;
  y = p.y;
  return *this;
}

Point& Point::operator+(const Point& p) {
  x += p.x;
  y += p.y;
  return *this;
}

void Point::SetPoint(unsigned int _x, unsigned int _y) {
  x = _x;
  y = _y;
}