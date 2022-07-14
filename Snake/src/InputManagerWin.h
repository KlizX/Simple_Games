#pragma once
#include "InputManager.h"

class InputManagerWin : public InputManager {
public:
  InputManagerWin() : InputManager() { }
  virtual int GetInput();
  virtual ~InputManagerWin() { }

private:
  InputManagerWin(const InputManagerWin& imw) = delete;
  InputManagerWin& operator=(const InputManagerWin& imw) = delete;
};
