#include "Engine.h"

Engine::Engine(unsigned int _r, unsigned int _c) {
  isGameLost = false;
  dir = 0;
  steps = 0;

  r = _r;
  c = _c;

  currPosX = 0;
  currPosY = 0;

  posX = c / 2;
  posY = r / 2;

  world = new bool* [r];

  for (unsigned int i = 0; i < r; i++) {
    world[i] = new bool[c];
  }

  for (unsigned int i = 0; i < r; i++) {
    for (unsigned int j = 0; j < c; j++) {
      world[i][j] = false;
    }
  }
}

void Engine::PositionUpdate() {
  dir %= 4;

  switch (dir) {
    case 0:
      if (posY == 0) {
        isGameLost = true;
        return;
      }
      posY--; 
      return;
    case 1:
      posX++;
      if (posX == c) {
        isGameLost = true;
      }
      return;
    case 2:
      posY++;
      if (posY == r) {
        isGameLost = true;
      };
      return;
    case 3:
      if (posX == 0) {
        isGameLost = true;
        return;
      }
      posX--;
      return;
  }
}

void Engine::Analyse() {
  currPosX = posX;
  currPosY = posY;
  (world[currPosY][currPosX]) ? dir-- : dir++;
  world[currPosY][currPosX] = !world[currPosY][currPosX];
  steps++;
  PositionUpdate();
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