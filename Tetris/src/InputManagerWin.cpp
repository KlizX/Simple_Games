#include <Windows.h>
#include "InputManagerWin.h"

int InputManagerWin::GetInput() {
  if (GetAsyncKeyState(keyLeft) & 1) {
    return -1;
  }

  if (GetAsyncKeyState(keyRight) & 1) {
    return 1;
  }

  if (GetAsyncKeyState(keyRotate) & 1) {
    return 5;
  }

  if (GetAsyncKeyState(keyDown) & 1) {
    return -999;
  }

  return 0;
}