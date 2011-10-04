
#include <state.hpp>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#include <bfs.hpp>

using namespace std;

class Quiz1Q1BFS : public State {
public:
  Quiz1Q1BFS(string name);
		
  spState clone();
  vector<spState> generateChildren();
  bool isGoal();
  int h();
  int g();
  bool equal(spState s);
};

Quiz1Q1BFS::Quiz1Q1BFS(string name) : State(name)
{
}

spState Quiz1Q1BFS::clone()
{
  auto n = make_shared<Quiz1Q1BFS>(name);
  return n;
}

vector<spState> Quiz1Q1BFS::generateChildren()
{
  vector<spState> lst;
  string adj;
	
  switch(name[0]) {
  case 'S':
    adj = "ABCD";
    break;
			
  case 'A':
    adj = "EJBS";
    break;
			
  case 'B':
    adj = "AFS";
    break;
			
  case 'C':
    adj = "GHDS";
    break;
			
  case 'D':
    adj = "CIS";
    break;
			
  case 'E':
    adj = "KJA";
    break;
			
  case 'F':
    adj = "JKB";
    break;
			
  case 'G':
    adj = "LC";
    break;
			
  case 'H':
    adj = "LMIC";
    break;
			
  case 'I':
    adj = "HD";
    break;
			
  case 'J':
    adj = "EFA";
    break;
			
  case 'K':
    adj = "FE";
    break;
			
  case 'L':
    adj = "MHG";
    break;
			
  case 'M':
    adj = "HL";
    break;
  }
	
  for_each(adj.begin(), adj.end(), [&](char c)
	   {
	     string s;
	     s = c;
	     lst.push_back(make_shared<Quiz1Q1BFS>(s));
	   });
	
  return lst;
}

bool Quiz1Q1BFS::isGoal()
{
  return name == "H";
}

int Quiz1Q1BFS::h()
{
  return -1;
}

int Quiz1Q1BFS::g()
{
  return -1;
}

bool Quiz1Q1BFS::equal(spState s)
{
  Quiz1Q1BFS* ss = dynamic_cast<Quiz1Q1BFS*>(s.get());
  return this->name == ss-> name;
}

int main(void)
{
  BFS *d = new BFS(make_shared<Quiz1Q1BFS>("S"));
  auto p = d->run();
	
  for_each(p->rbegin(), p->rend(), [](spState s)
	   {
	     cout << s->repr() << "\t";
	   });
  cout << "\n";
	
  return 0;
}
