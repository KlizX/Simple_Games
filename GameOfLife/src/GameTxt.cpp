#include "GameTxt.h"
#include <iostream>
#include <Windows.h>

void GameTxt::View() {
  system("cls");
  std::string viewStream;
  viewStream.clear();
  for (int i = 1; i < (r - 1); i++) {
    for (int j = 1; j < (c - 1); j++) {
      viewStream += (cell[i][j]) ? 'X' : ' ';
    }
    viewStream += '\n';
  }
  std::cout << viewStream << '\n';
  std::cout << "Press ENTER to see next generation" << '\n';
  std::cout << "Press SOMETHING + ENTER to exit program" << '\n';
}