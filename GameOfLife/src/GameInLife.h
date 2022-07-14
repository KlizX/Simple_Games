#pragma once
#include "Engine.h"

class GameInLife : public Engine {
  protected:
    GameInLife(int _r, int _c) : Engine(_r, _c) { }

  public:
    void Play();
    virtual void View() = 0;
    virtual ~GameInLife() { }

  private:
    GameInLife(const GameInLife& gil);
    GameInLife& operator=(const GameInLife& gil);
};