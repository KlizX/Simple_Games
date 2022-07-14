#include <iostream>
#include <ctime>
#include "Engine.h"

Engine::Engine(InputManager* _im) : r(20), c(10), isLost(false), isFigure(false), idFigure(0), im(_im) {
  board = new bool* [r];

  for (int i = 0; i < r; i++) {
    board[i] = new bool[c];
  }

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      board[i][j] = false;
    }
  }
}

bool Engine::isSpaceForFigure() {
  for (int i = 0; i < 4; i++) {
    if (f[i].x < 0 || f[i].x >= c || f[i].y < 0 || f[i].y >= r) return false;
    if (board[f[i].y][f[i].x]) return false;
  }
  return true;
}

void Engine::ApplyNewFigurePos() {
  for (int i = 0; i < 4; i++) {
    board[f[i].y][f[i].x] = true;
  }
  View();
}

void Engine::DeleteOldFigurePos() {
  for (int i = 0; i < 4; i++) {
    board[f[i].y][f[i].x] = false;
  }
}

void Engine::GenerateFigure() {
  int figures[7][4] = {
    3, 2, 1, 5,
    5, 3, 1, 7,
    3, 0, 1, 5,
    3, 4, 1, 5,
    3, 2, 1, 4,
    3, 0, 2, 5,
    3, 2, 4, 5,
  };

  srand(unsigned int(time(NULL)));
  idFigure = rand() % 7;

  for (int i = 0; i < 4; i++) {
    f[i].x = figures[idFigure][i] / 2 + 3;
    f[i].y = figures[idFigure][i] % 2;
  }

  if (!isSpaceForFigure()) {
    isLost = true;
  }

  isFigure = true;

  ApplyNewFigurePos();
}

void Engine::FallFigure() {
  DeleteOldFigurePos();

  for (int i = 0; i < 4; i++) {
    copyF[i] = f[i];
    f[i].y += 1;
  }

  if (!isSpaceForFigure()) {
    for (int i = 0; i < 4; i++) {
      f[i] = copyF[i];
      isFigure = false;
    }
  }

  ApplyNewFigurePos();

  if (!isFigure) {
    CheckRows();
  }
}

void Engine::RotateFigure() {
  if (idFigure != 6) {
    DeleteOldFigurePos();
    Point p = f[0];
    int x, y;

    for (int i = 0; i < 4; i++) {
      copyF[i] = f[i];
      x = f[i].y - p.y;
      y = f[i].x - p.x;
      f[i].x = p.x - x;
      f[i].y = p.y + y;
    }

    if (!isSpaceForFigure()) {
      for (int i = 0; i < 4; i++) {
        f[i] = copyF[i];
      }
      return;
    }

    ApplyNewFigurePos();
  }
}

void Engine::MoveFigure(int dir) {
  DeleteOldFigurePos();

  for (int i = 0; i < 4; i++) {
    copyF[i] = f[i];
    f[i].x += dir;
  }

  if (!isSpaceForFigure()) {
    for (int i = 0; i < 4; i++) {
      f[i] = copyF[i];
    }
    return;
  }

  ApplyNewFigurePos();
}

void Engine::GameFrame(int t) {
  int t0 = clock();
  while (clock() - t0 < t) {
    int keyCode = im->GetInput();
    if (keyCode == -999) {
      break;
    }
    else if (keyCode == 5) {
      RotateFigure();
    }
    else if (keyCode != 0) {
      MoveFigure(keyCode);
    }
  }
  FallFigure();
}

void Engine::CheckRows() {
  int k = r - 1;
  for (int i = r - 1; i > 0; i--)
  {
    int countCells = 0;
    for (int j = 0; j < c; j++)
    {
      if (board[i][j]) countCells++;
      board[k][j] = board[i][j];
    }
    if (countCells < c) k--;
  }
  View();
}

void Engine::ApplyPhysics() {
  if (!isFigure) {
    GenerateFigure();
  }
  GameFrame(1000);
}

Engine::~Engine() {
  for (int i = 0; i < r; i++) {
    delete[] board[i];
  }
  delete[] board;
  board = nullptr;
}