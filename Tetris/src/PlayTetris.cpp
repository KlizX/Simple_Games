#include "PlayTetris.h"

void PlayTetris::Play() {
  View();
  while (!isLost) {
    ApplyPhysics();
  }
}