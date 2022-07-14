#pragma once

class Engine {
  protected:
    unsigned int r, c;
    unsigned int steps;
    unsigned int currPosX, currPosY;
    unsigned int posX, posY;
    unsigned int dir; // 0 - N, 1 - E, 2 - S, 3 - W
    bool isGameLost;
    bool** world;

  private:
    void PositionUpdate();

  protected:
    Engine(unsigned int _r, unsigned int _c);
    void Analyse();
    virtual ~Engine();

  private:
    Engine(const Engine& e) = delete;
    Engine& operator=(const Engine& e) = delete;
};