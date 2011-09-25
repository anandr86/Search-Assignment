
#include <search.hpp>
#include <best_first.hpp>
#include <vector>
#include <string>
#include <algorithm>

#include <iostream>	

using namespace std;

BestFirst::BestFirst(State* start) : Search(start)
{
}

vector<State*>* BestFirst::run()
{
	auto comp_fn = [](State* s1, State* s2) { return s1->h() > s2 -> h(); };
	vector<State*> closed, open;	
	open.push_back(start->clone());
	
	while(!open.empty()) {
		State* best = open.front();
		pop_heap(open.begin(), open.end(), comp_fn);
		open.pop_back();
		
		closed.push_back(best);
		
		auto ch = best->generateChildren();
		
		// check for goal
		for(auto i = ch.begin(); i != ch.end(); i++) {
			if((*i)->isGoal()) {
				return constructPath(*i);
			}
		}
		
		// remove duplicates from closed
		auto mark = remove_if(ch.begin(), ch.end(), [&](State* s) {
			return find_if(closed.begin(), closed.end(), [&](State* ss){ return ss->equal(s);}) != closed.end();
		});
		ch.erase(mark, ch.end());
		
		// remove duplicated from open
		mark = remove_if(ch.begin(), ch.end(), [&](State* s) {
			return find_if(open.begin(), open.end(), [&](State* ss){ return ss->equal(s);}) != open.end();
		});
		ch.erase(mark, ch.end());
		
		// add to open list
		for_each(ch.begin(), ch.end(), [&](State* s) {
			open.push_back(s);
			push_heap(open.begin(), open.end(), comp_fn);
		});
	}
	
	return nullptr;
}

void BestFirst::reset()
{
}