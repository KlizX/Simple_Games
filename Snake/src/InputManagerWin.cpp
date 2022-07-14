#include <Windows.h>
#include "InputManagerWin.h"

int InputManagerWin::GetInput() {
  if (GetAsyncKeyState(keyNorth) & 1) {
    return 0;
  }

  if (GetAsyncKeyState(keySouth) & 1) {
    return 1;
  }

  if (GetAsyncKeyState(keyEast) & 1) {
    return 2;
  }

  if (GetAsyncKeyState(keyWest) & 1) {
    return 3;
  }

  return -1;
}
