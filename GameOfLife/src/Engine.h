#pragma once

class Engine {
  protected:
    int r, c;
    bool** cell;
    bool** tmpCell;


  protected:
    Engine(int _r, int _c);
    void Init(const char* fName = "data.cfg");
    void Analyse();
    virtual ~Engine();

  private:
    int CountNeighbours(int i, int j);
    bool NewStatus(int i, int j);

  private:
    Engine(const Engine& e);
    Engine& operator=(const Engine& e);
};