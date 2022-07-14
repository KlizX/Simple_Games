#pragma once

class Point {
  private:
    unsigned int x, y;

  public:
    Point() : x(0), y(0) { }
    Point(unsigned int _x, unsigned int _y) : x(_x), y(_y) { }
    Point& operator=(const Point& p);
    Point& operator+(const Point& p);
    Point(const Point& p);
    void SetPoint(unsigned int _x, unsigned int _y);
    ~Point() { }

  friend class Engine;
};
