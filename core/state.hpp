
#ifndef __STATE_HPP__
#define __STATE_HPP__

#include <string>
#include <vector>
#include <memory>

class State;

typedef std::shared_ptr<State> spState;

class State {
  static void* blob;
  spState parent;
	
protected:
  std::string name;
    
public:
  static void setBlob(void* b);
  static void* getBlob();

  State(std::string name);
  void setParent(spState s);
  spState getParent();
  virtual std::string repr();

  virtual spState clone() = 0;
  virtual std::vector<spState> generateChildren() = 0;
  virtual bool isGoal() = 0;
  virtual int h() = 0;
  virtual int g() = 0;
  virtual bool equal(spState s) = 0;
};

#endif // __STATE_HPP__
