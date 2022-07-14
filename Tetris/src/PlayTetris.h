#pragma once
#include "Engine.h"

class PlayTetris : public Engine {
  protected:
    PlayTetris(InputManager* _im) : Engine(_im) { }

  public:
    void Play();
    virtual ~PlayTetris() { }

  private:
    PlayTetris(const PlayTetris& pt) = delete;
    PlayTetris& operator=(const PlayTetris& pt) = delete;
};