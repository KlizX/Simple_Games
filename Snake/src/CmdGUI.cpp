#include "CmdGUI.h"
#include <Windows.h>
#include <iostream>

void CmdGUI::View() {
  system("cls");
  out = "";

  for (unsigned int i = 0; i < r; i++) {
    for (unsigned int j = 0; j < c; j++) {
      if (i == 0 || i == (r - 1)) {
        out += wallTexture;
      }
      else if (j == 0 || j == (c - 1)) {
        out += wallTexture;
      }
      else {
        if (world[i][j] == 0) out += bgTexture;
        else if (world[i][j] == 1) out += snakeTexture;
        else out += fruitTexture;
      }
    }
    out += '\n';
  }
  std::cout << out;
  std::cout << "Score: " << score << '\n';
  std::cout << "Score: " << speed << '\n';
}