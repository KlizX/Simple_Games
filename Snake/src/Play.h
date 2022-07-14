#pragma once
#include "Engine.h"

class Play : public Engine {
  protected:
    Play(InputManager* _im) : Engine(_im) { }

  public:
    void PlayGame();
    virtual void View() = 0;
    virtual ~Play() { }

  private:
    Play(const Play& p) = delete;
    Play& operator=(const Play& p) = delete;
};