#include "Play.h"
#include <ctime>

void Play::PlayGame() {
  while (!isGameOver) {
    View();
    ApplyDir();

    unsigned int t0 = clock();
    while (clock() - t0 < speed) {
      SetDir();
    }
  }
}