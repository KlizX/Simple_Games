#pragma once
#include <vector>
#include "InputManager.h"
#include "Point.h"

class Engine {
  protected:
    InputManager* im;
    unsigned int r, c;
    unsigned int speed;
    unsigned int score;
    enum class Direction {kNorth = 0, kSouth, kEast, kWest};
    Direction dir;
    Direction oldDir;
    std::vector<Point> posSnake;
    int** world;
    bool isGameOver;

  protected:
    Engine(InputManager* _im);
    void SetDir();
    void ApplyDir();
    void GenerateFruitPos();
    virtual ~Engine();
    
  private:
    Engine(const Engine& e) = delete;
    Engine& operator=(const Engine& e) = delete;
};