
#include <search.hpp>
#include <state.hpp>
#include <vector>

using namespace std;

Search::Search(State* st) : start(st)
{
}

vector<State*>* Search::constructPath(State* s)
{
    vector<State*>* path = new vector<State*>();
    while(s != nullptr) {
        path->push_back(s);
        s = s->getParent();
    }

    return path;
}