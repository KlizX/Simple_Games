#pragma once
#include "Engine.h"

class Play : public Engine {
  protected:
    Play(unsigned int _r, unsigned int _c) : Engine(_r, _c) { }

  public:
    void PlayGame();
    virtual void View() = 0;
    virtual void ViewSteps() = 0;
    virtual ~Play() { }

  private:
    Play(const Play& p) = delete;
    Play& operator=(const Play& p) = delete;
};