
#include <dfs.hpp>
#include <search.hpp>
#include <state.hpp>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

DFS::DFS(State* start) : Search(start)
{
}

std::vector<State*>* DFS::run()
{
    vector<State*> open;
    vector<State*> closed;

    open.push_back(start->clone());
    while(!open.empty()) {
        State* c = open.back();
		open.pop_back();
		closed.push_back(c);

        //generate children
        auto ch = c->generateChildren();

        //check for goal condition
        for(auto i = ch.begin(); i != ch.end(); i++) {

            //Found goal. Compute path and return
            if((*i)->isGoal()) {
                return constructPath(*i); // we are using linked states. No need for closed list
            }
        }

        //check closed list and prune
        auto mark = remove_if(ch.begin(), ch.end(), [&](State* s)
                    {
                        return find_if(closed.begin(), closed.end(), [&](State* ss) { return ss->equal(s);}) != closed.end();
                    });
        ch.erase(mark, ch.end());

        //check open list and prune
        mark = remove_if(ch.begin(), ch.end(), [&](State* s)
			   {
					return find_if(open.begin(), open.end(), [&](State* ss) { return ss->equal(s);}) != open.end();
			   });
        ch.erase(mark, ch.end());

        //add children to open list
        copy(ch.rbegin(), ch.rend(), back_inserter(open));
    }
	
	return nullptr;
}

void DFS::reset()
{
}