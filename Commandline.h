// Name: Adedotun Odutola
// userID: aco0008
// File Name: Commandline.h
// Mac Terminal Make file compiler was used.


#ifndef COMMANDLINE_H_
#define COMMANDLINE_H_

#include <iostream>
using namespace std;

namespace auDisk {
class Commandline {
public:
	Commandline();
	int setInterval(int value);
	int setCount(int value);
	string setReportName(string name);
	int setBlk_Read(int value);
	int setBlk_Read_S(int value);
	int setKb_Read(int value);
	int setBlk_Write(int value);
	int setBlkWrite_S(int value);
	int setKb_Write(int value);
	void help();

};
}
#endif /* COMMANDLINE_H_ */

