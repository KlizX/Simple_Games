#pragma once
#include "PlayTetris.h"
#include "InputManagerWin.h"

class GameTxt : public PlayTetris {
  public:
    GameTxt() : PlayTetris(new InputManagerWin()) { }
    virtual void View();
    virtual ~GameTxt() { }

  private:
    GameTxt(const GameTxt& gt) = delete;
    GameTxt& operator=(const GameTxt& gt) = delete;
};