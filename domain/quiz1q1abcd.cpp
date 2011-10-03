
#include <state.hpp>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#include <dfs.hpp>

using namespace std;

class Quiz1Q1 : public State {
public:
  Quiz1Q1(string name);
		
  spState clone();
  vector<spState> generateChildren();
  bool isGoal();
  int h();
  int g();
  bool equal(spState s);
};

Quiz1Q1::Quiz1Q1(string name) : State(name)
{
}

spState Quiz1Q1::clone()
{
  auto n = make_shared<Quiz1Q1>(name);
  return n;
}

vector<spState> Quiz1Q1::generateChildren()
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
	     lst.push_back(make_shared<Quiz1Q1>(s));
	   });
	
  return lst;
}

bool Quiz1Q1::isGoal()
{
  return name == "H";
}

int Quiz1Q1::h()
{
  return -1;
}

int Quiz1Q1::g()
{
  return -1;
}

bool Quiz1Q1::equal(spState s)
{
  Quiz1Q1* ss = dynamic_cast<Quiz1Q1*>(s.get());
  return this->name == ss-> name;
}

int main(void)
{
  DFS *d = new DFS(make_shared<Quiz1Q1>("S"));
  auto p = d->run();
	
  for_each(p->rbegin(), p->rend(), [](spState s)
	   {
	     cout << s->repr() << "\t";
	   });
  cout << "\n";
	
  return 0;
}
