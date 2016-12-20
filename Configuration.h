// Name: Adedotun Odutola
// userID: aco0008
// File Name: Configuration.h
// Mac Terminal Make file compiler was used.


#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

namespace auDisk {
class Configuration {
public:
	int interval;
	int count;
	string reportName;
	int blk_Read_Conf;
	int blk_Read_S_Conf;
	int kb_Read_S_Conf;
	int blk_Write_Conf;
	int blk_Write_S_Conf;
	int kb_Write_Conf;
	Configuration();
	void ReadConf();
	void printConf();
	void save();
private:
	string fileName;
	ifstream confFile;
	ofstream confSave;
};
}
#endif /* CONFIGURATION_H_ */

