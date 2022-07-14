#include <fstream>
#include <iostream>
#include "Engine.h"

Engine::Engine(int _r, int _c) {
  r = _r;
  c = _c;
  Init();
}

void Engine::Init(const char* fName) {
  int seed = 10;
  std::string command;
  std::ifstream file(fName);
  if (file.good()) {
    file >> command;
    file >> c;
    file >> command;
    file >> r;
    file >> command;
    file >> seed;
  }

  c += 2;
  r += 2;

  cell = new bool* [r];
  tmpCell = new bool* [r];
  for (int i = 0; i < r; i++) {
    cell[i] = new bool[c];
    tmpCell[i] = new bool[c];
  }

  for (int i = 0; i < c; i++) {
    cell[0][i] = false;
    cell[r - 1][i] = false;
  }

  for (int i = 1; i < (r - 1); i++) {
    cell[i][0] = false;
    cell[i][c - 1] = false;
  }

  srand(seed);
  int temp;
  for (int i = 1; i < (r - 1); i++) {
    for (int j = 1; j < (c - 1); j++) {
      temp = rand() % 100;
      cell[i][j] = (temp % 3 == 0) ? true : false;
    }
  }

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      tmpCell[i][j] = false;
    }
  }
}

void Engine::Analyse() {
  for (int i = 1; i < (r - 1); i++) {
    for (int j = 1; j < (c - 1); j++) {
      if (!cell[i][j] && CountNeighbours(i, j) == 3) tmpCell[i][j] = true;
      else if (cell[i][j] && (CountNeighbours(i, j) != 2 && CountNeighbours(i, j) != 3)) tmpCell[i][j] = false;
      else tmpCell[i][j] = cell[i][j];
    }
  }

  for (int i = 1; i < (r - 1); i++) {
    for (int j = 1; j < (c - 1); j++) {
      cell[i][j] = NewStatus(i, j);
    }
  }
}

bool Engine::NewStatus(int i, int j) {
  return tmpCell[i][j];
}

int Engine::CountNeighbours(int i, int j) {
  int countNeighbours = 0;

  if (cell[i - 1][j - 1]) countNeighbours++;    //Gora lewo
  if (cell[i - 1][j]) countNeighbours++;        //Gora  
  if (cell[i - 1][j + 1]) countNeighbours++;    //Gora prawo

  if (cell[i][j + 1]) countNeighbours++;        //Prawo
  if (cell[i][j - 1]) countNeighbours++;        //Lewo

  if (cell[i + 1][j - 1]) countNeighbours++;    //Dol lewo
  if (cell[i + 1][j]) countNeighbours++;        //Dol
  if (cell[i + 1][j + 1]) countNeighbours++;    //Dol prawo
  
  return countNeighbours;
}

Engine::~Engine() {
  for (int i = 0; i < r; i++) {
    delete[] cell[i];
    delete[] tmpCell[i];
  }
  delete[] cell;
  cell = nullptr;
  delete[] tmpCell;
  tmpCell = nullptr;
}