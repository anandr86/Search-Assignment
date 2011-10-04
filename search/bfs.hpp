
#ifndef __BFS_HPP__
#define __BFS_HPP__

#include <search.hpp>
#include <state.hpp>
#include <memory>

class BFS : public Search {
public:
  BFS(spState start);
  virtual std::shared_ptr<std::vector<spState>> run();
  virtual void reset();
};

#endif // __BFS_HPP__
