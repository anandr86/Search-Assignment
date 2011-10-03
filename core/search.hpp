
#ifndef __SEARCH_HPP__
#define __SEARCH_HPP__

#include <state.hpp>
#include <memory>

class Search {
protected:
  spState const start;
  std::shared_ptr<std::vector<spState>> constructPath(spState s);
public:
  Search(spState start);
  virtual std::shared_ptr<std::vector<spState>> run() = 0;
  virtual void reset() = 0;
};

#endif //__SEARCH_HPP__
