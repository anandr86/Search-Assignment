
Changes 03/10/2011
* Changed interfaces to work with shared_ptr - Fixes memory leak issue
* Back to working with emacs - indentation changes for all files


Search framework

Directories:
	core	-	state and search interfaces
	search	-	implementation of search algorithms
	domain	-	implementation examples of search domains
	build	-	dummy directory for building stuff using cmake
	
Core
	search.cpp - Search interface
	state.cpp  - State interface
	
Search
	dfs.cpp	- DFS implementation
	best_first.cpp - Best first search implementation
