#include "Play.h"
#include <iostream>

void Play::PlayGame() {
  while (!isGameLost) {
    Analyse();
  }
  View();
  ViewSteps();
  std::cin.get();
}