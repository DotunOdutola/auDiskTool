// Name: Adedotun Odutola
// userID: aco0008
// File Name: Report.h
// Mac Terminal Make file compiler was used.


#ifndef REPORT_H_
#define REPORT_H_

#include <iostream>
#include <vector>
#include <fstream>
#include "Configuration.h"
#include <sstream>
using namespace std;

namespace auDisk {
typedef unsigned long ulong_t;
class Report {
public:
	struct report {
	string device;
	ulong_t blk_Read;
	ulong_t blk_Read_S;
	ulong_t kb_Read_S;
	ulong_t blk_Write;
	ulong_t kb_Write_S;
	ulong_t blk_Write_S;
	};
	report rep;
	vector<report> storeReports;
	void createReport();
	void printReport();
private:
	Configuration conf;
	ifstream reportName;
	ofstream madeName;
};
}
#endif /* REPORT_H_ */

