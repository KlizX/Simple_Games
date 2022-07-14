#pragma once
#include "GameInLife.h"

class GameTxt : public GameInLife {
  public:
    GameTxt(int _r = 20, int _c = 100) : GameInLife(_r, _c) { }
    void View();
    virtual ~GameTxt() { }

  private:
    GameTxt(const GameTxt& gt);
    GameTxt& operator=(const GameTxt& gt);
};