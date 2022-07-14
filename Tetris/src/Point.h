#pragma once

class Point {
  public:
    int x, y;

  private:
    Point() : x(0), y(0) { }
    Point& operator=(const Point& p);
    Point(const Point& p);
    ~Point() { }

    friend class Engine;
};