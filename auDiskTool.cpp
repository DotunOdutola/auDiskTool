// Name: Adedotun Odutola
// userID: aco0008
// File Name: auDiskTool.cpp
// Mac Terminal Make file compiler was used.


#include "Tool.h"
using namespace auDisk;

//#define TESTING
#ifdef TESTING
int main() {
	cout << "****Start Testing****\n";
	Tool tool;
	tool.testRun();
	tool.testSetRun();
	tool.testprint();
	tool.testSave();
	tool.testHelp();
	return 0;
}
#else
int main() {
	Tool tool;
	tool.toolInterface();
return 0;
}
#endif

