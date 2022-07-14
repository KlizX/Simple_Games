#include "Engine.h"

Engine::Engine(InputManager* _im) : im(_im){
  r = 20;
  c = 25;
  speed = 250;
  dir = Direction::kNorth;
  oldDir = Direction::kNorth;
  isGameOver = false;
  score = 1;

  posSnake.push_back(Point(c / 2, r / 2 - 1));
  posSnake.push_back(Point(c / 2, r / 2));
  posSnake.push_back(Point(c / 2, r / 2 + 1));

  world = new int* [r];
  
  for (unsigned int i = 0; i < r; i++) {
    world[i] = new int[c];
  }
  
  for (unsigned int i = 0; i < r; i++) {
    for (unsigned int j = 0; j < c; j++) {
      world[i][j] = 0;
    }
  }

  for (Point& p : posSnake) {
    world[p.y][p.x] = 1;
  }

  GenerateFruitPos();
}

void Engine::SetDir() {
  switch (im->GetInput()) {
    case 0: 
      if (oldDir != Direction::kSouth) {
        dir = Direction::kNorth;
      }
      break;
    case 1: 
      if (oldDir != Direction::kNorth) {
        dir = Direction::kSouth;
      }
      break;
    case 2: 
      if (oldDir != Direction::kWest) {
        dir = Direction::kEast;
      }
      break;
    case 3:
      if (oldDir != Direction::kEast) {
        dir = Direction::kWest;
      }
      break;
  }
}


void Engine::ApplyDir() {
  Point vDir;
  switch (dir) {
    case Direction::kNorth:
      vDir.SetPoint(0, -1);
      break;
    case Direction::kSouth:
      vDir.SetPoint(0, 1);
      break;
    case Direction::kEast:
      vDir.SetPoint(1, 0);
      break;
    case Direction::kWest:
      vDir.SetPoint(-1, 0);
      break;
  }

  Point oldPos = posSnake.back();
  for (unsigned int i = posSnake.size() - 1; i > 0 ; i--) {
    posSnake[i] = posSnake[i - 1];
  }
  world[oldPos.y][oldPos.x] = 0;

  posSnake.front() = posSnake.front() + vDir;
  Point newPos = posSnake.front();

  if (world[newPos.y][newPos.x] == -1) {
    score++;
    posSnake.push_back(oldPos);
    GenerateFruitPos();
  }
  else if (world[newPos.y][newPos.x] == 1) {
    isGameOver = true;
  }

  world[newPos.y][newPos.x] = 1;
  oldDir = dir;

  if (newPos.x == 0 || newPos.x == (c - 1)) {
    isGameOver = true;
  }

  if (newPos.y == 0 || newPos.y == (r - 1)) {
    isGameOver = true;
  }
}

void Engine::GenerateFruitPos() {
  Point posFruit;
  bool isCellFree = false;
  do {
    posFruit.x = rand() % (c - 2) + 1;
    posFruit.y = rand() % (r - 2) + 1;
  } while (world[posFruit.y][posFruit.x] == 1);
  world[posFruit.y][posFruit.x] = -1;
}

Engine::~Engine() {
  if (world) {
    for (unsigned int i = 0; i < r; i++) {
      delete[] world[i];
    }
    delete[] world;
    world = nullptr;
  }
}