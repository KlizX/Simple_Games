#include "Play.h"

class CmdGUI : public Play {
  private:
    char antTexture;

  public:
    CmdGUI(unsigned int _r, unsigned int _c) : Play(_r, _c), antTexture(char(178)) { }
    void View();
    void ViewSteps();
    virtual ~CmdGUI() { }

  private:
    CmdGUI(const CmdGUI& c) = delete;
    CmdGUI& operator=(const CmdGUI& c) = delete;
};