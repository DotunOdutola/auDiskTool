// Name: Adedotun Odutola
// userID: aco0008
// File Name: Tool.h
// Mac Terminal Make file compiler was used.


#ifndef TOOL_H_
#define TOOL_H_

#include <iostream>
#include "Report.h"
#include "Commandline.h"
#include "Configuration.h"
#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <ctype.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <cassert>
#include <sstream>
#include <unistd.h>
using namespace std;

namespace auDisk {
typedef unsigned long ulong_t;
class Tool {
public:
	Tool();
	void toolInterface();
	void run();
	void testRun();
	void testSetRun();
	void testprint();
	void testSave();
	void testHelp();
private:
	struct devStats {
		string decoy1;
		string decoy2;
		string devName;
		ulong_t reads;
		ulong_t readMerge;
		ulong_t writes;
		ulong_t secReading;
		ulong_t mSecondsRead;
		ulong_t writeCompleted;
		ulong_t secWritting;
		ulong_t mSecondWrite;
		ulong_t currentI_O;
		ulong_t mSecondsI_O;
		ulong_t weightedI_O;
	};
	vector<devStats> stats;
	vector<devStats> stats1;
	ifstream allDevicesFile;
	string fileNameAll;
	Report report;
	Commandline cmd;
	Configuration conf;
	devStats dev;
	devStats dev1;
};
}
#endif /* TOOL_H_ */

