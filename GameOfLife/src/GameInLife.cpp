#include "GameInLife.h"
#include <iostream>

void GameInLife::Play() {
  char key;
  do {
    View();
    Analyse();
    std::cin.get(key);
  } while (key == '\n');
}