#include <iostream>
#include <Windows.h>
#include <string>
#include "GameTxt.h"

void GameTxt::View() {
  system("cls");
  std::string bufView = "";

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      bufView += board[i][j] ? 'x' : ' ';
    }
    bufView += '\n';
  }

  std::cout << bufView;
}