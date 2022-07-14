#pragma once

class InputManager {
protected:
  char keyNorth;
  char keySouth;
  char keyEast;
  char keyWest;

protected:
  InputManager() : keyWest('A'), keyEast('D'), keySouth('S'), keyNorth('W') { }

public:
  virtual int GetInput() = 0;
  virtual ~InputManager() { }

private:
  InputManager(const InputManager& im) = delete;
  InputManager& operator=(const InputManager& im) = delete;
};
