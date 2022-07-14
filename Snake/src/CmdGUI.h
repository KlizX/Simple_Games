#pragma once
#include "Play.h"
#include "InputManagerWin.h"
#include <string>

class CmdGUI : public Play {
  private:
    char snakeTexture;
    char wallTexture;
    char bgTexture;
    char fruitTexture;
    std::string out;

  public:
    CmdGUI() : Play(new InputManagerWin()), snakeTexture(char(178)), bgTexture(' '), fruitTexture('O'), wallTexture('#'), out("") { }
    void View();
    virtual ~CmdGUI() { }

  private:
    CmdGUI(const CmdGUI& c) = delete;
    CmdGUI& operator=(const CmdGUI& c) = delete;
};