#pragma once

class InputManager {
  protected:
    char keyLeft;
    char keyRight;
    char keyDown;
    char keyRotate;

  protected:
    InputManager() : keyLeft('A'), keyRight('D'), keyDown('S'), keyRotate('W') { }
  
  public:
    virtual int GetInput() = 0;
    virtual ~InputManager() { }

  private:
    InputManager(const InputManager& im) = delete;
    InputManager& operator=(const InputManager& im) = delete;
};