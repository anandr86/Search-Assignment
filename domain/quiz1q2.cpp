
#include <search.hpp>
#include <state.hpp>
#include <best_first.hpp>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

class Quiz1Q2 : public State {
	public:
		Quiz1Q2(string name, State* parent = nullptr);
		State* clone();
		vector<State*> generateChildren();
		bool isGoal();
		int h();
		int g();
		bool equal(State* s);
};

Quiz1Q2::Quiz1Q2(string name, State* parent) : State(name, parent)
{
}

State* Quiz1Q2::clone()
{
	State* s = new Quiz1Q2(repr(), getParent());
	return s;
}

vector<State*> Quiz1Q2::generateChildren()
{
	vector<State*> ret;
	string ch;
	
	switch(name[0]) {
		case 'S':
			ch = "HD";
			break;
			
		case 'H':
			ch = "SD";
			break;
			
		case 'D':
			ch = "SHIA";
			break;
			
		case 'I':
			ch = "ODLJ";
			break;
			
		case 'A':
			ch = "DFB";
			break;
			
		case 'J':
			ch = "ILF";
			break;
			
		case 'L':
			ch = "IJQ";
			break;
			
		case 'Q':
			ch = "L";
			break;
			
		case 'O':
			ch = "HIP";
			break;
			
		case 'P':
			ch = "OR";
			break;
			
		case 'R':
			ch = "PT";
			break;
			
		case 'T':
			ch = "RG";
			break;
			
		case 'G':
			ch = "TMK";
			break;
			
		case 'F':
			ch = "AJK";
			break;
			
		case 'B':
			ch = "ACK";
			break;
			
		case 'K':
			ch = "BFEMG";
			break;
			
		case 'M':
			ch = "KG";
			break;
			
		case 'C':
			ch = "BE";
			break;
			
		case 'E':
			ch = "CK";
			break;
	}
	
	for_each(ch.begin(), ch.end(), [&](char c) {
		string ss;
		ss = c;
		ret.push_back(new Quiz1Q2(ss, this));
	});
	
	return ret;
}

bool Quiz1Q2::isGoal()
{
	return name[0] == 'G';
}

int Quiz1Q2::h()
{
	auto hmap = static_cast<map<string, int>*>(State::getBlob());
	
	return hmap->at(this->name);
}

int Quiz1Q2::g()
{
	return -1;
}

bool Quiz1Q2::equal(State* s)
{
	Quiz1Q2* ss = dynamic_cast<Quiz1Q2*>(s);
	return name[0] == ss->name[0];
}

int main()
{
	map<string, int> hmap;
	hmap["S"] = 140;
	hmap["H"] = 120;
	hmap["D"] = 100;
	hmap["A"] = 110;
	hmap["O"] = 100;
	hmap["I"] = 100;
	hmap["L"] = 70;
	hmap["J"] = 90;
	hmap["Q"] = 50;
	hmap["F"] = 80;
	hmap["P"] = 80;
	hmap["R"] = 60;
	hmap["B"] = 100;
	hmap["C"] = 80;
	hmap["T"] = 20;
	hmap["G"] = 0;
	hmap["K"] = 40;
	hmap["M"] = 40;
	hmap["E"] = 50;

	State::setBlob(&hmap);
	State *st = new Quiz1Q2("S");
	BestFirst* bfs = new BestFirst(st);
	auto p = bfs->run();
	
	for_each(p->rbegin(), p->rend(), [](State* s) {
		cout << s->repr() << "\t";
	});
	
	cout << "\n";
	return 0;
}