#pragma once
#include "Point.h"
#include "InputManager.h"

class Engine {
  private:
    int idFigure;
    Point f[4];
    Point copyF[4];
    InputManager* im;

  protected:
    const int r, c;
    bool** board;
    bool isLost;
    bool isFigure;

  private:
    bool isSpaceForFigure();
    void ApplyNewFigurePos();
    void DeleteOldFigurePos();
    void GenerateFigure();
    void FallFigure();
    void RotateFigure();
    void MoveFigure(int dir);
    void GameFrame(int t);
    void CheckRows();

  protected:
    Engine(InputManager* _im);
    void ApplyPhysics();

  public:
    virtual void View() = 0;
    virtual ~Engine();

  private:
    Engine(const Engine& e) = delete;
    Engine& operator=(const Engine& e) = delete;
};