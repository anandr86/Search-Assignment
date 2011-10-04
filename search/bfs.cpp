
#include <bfs.hpp>
#include <search.hpp>
#include <state.hpp>
#include <string>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
#include <memory>

using namespace std;

BFS::BFS(spState start) : Search(start)
{
}

shared_ptr<vector<spState>> BFS::run()
{
  list<spState> open;
  vector<spState> closed;

  open.push_back(start->clone());
  while(!open.empty()) {
    spState c = open.front();
    open.pop_front();
    closed.push_back(c);

    //generate children
    auto ch = c->generateChildren();

    for_each(ch.begin(), ch.end(), [&](spState s)
	     {
	       s->setParent(c);
	     });

    //check for goal condition
    for(auto i = ch.begin(); i != ch.end(); i++) {

      //Found goal. Compute path and return
      if((*i)->isGoal()) {
	return constructPath(*i); // we are using linked states. No need for closed list
      }
    }

    //check closed list and prune
    auto mark = remove_if(ch.begin(), ch.end(), [&](spState s)
			  {
			    return find_if(closed.begin(), closed.end(), [&](spState ss) { return ss->equal(s);}) != closed.end();
			  });
    ch.erase(mark, ch.end());

    //check open list and prune
    mark = remove_if(ch.begin(), ch.end(), [&](spState s)
		     {
		       return find_if(open.begin(), open.end(), [&](spState ss) { return ss->equal(s);}) != open.end();
		     });
    ch.erase(mark, ch.end());

    //add children to open list
    copy(ch.rbegin(), ch.rend(), back_inserter(open));
  }
	
  return nullptr;
}

void BFS::reset()
{
}
