#include <iostream>
#include "CmdGUI.h"

void CmdGUI::View() {
  std::string str = "";
  for (unsigned int i = 0; i < r; i++) {
    for (unsigned int j = 0; j < c; j++) {
      str += (world[i][j]) ? antTexture : ' ';
    }
    str += '\n';
  }
  std::cout << str;
}

void CmdGUI::ViewSteps() {
  std::cout << "Steps: " << steps << '\n';
}