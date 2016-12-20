// Name: Adedotun Odutola
// userID: aco0008
// File Name: Report.cpp
// Mac Terminal Make file compiler was used.

#include "Report.h"
namespace auDisk {
void Report::createReport() {
	stringstream ss;
	stringstream ss1;
	stringstream ss2;
	stringstream ss3;
	stringstream ss4;
	stringstream ss5;
	madeName.open((char*)conf.reportName.c_str());
	madeName << "Device blk_read blk_read/s kb_read/s blk_write blk_write/s kb_write/s\n";
	for (int i = 0; i < conf.count; i++) {
		ss << storeReports[i].blk_Read;
		string read = ss.str();
		ss.str("");
		ss.clear();
		ss1 << storeReports[i].blk_Read_S;
		string read_S = ss1.str();
		ss1.str("");
		ss1.clear();
		ss2 << storeReports[i].kb_Read_S;
		string kbRead = ss2.str();
		ss2.str("");
		ss2.clear();
		ss3 << storeReports[i].blk_Write;
		string write = ss3.str();
		ss3.str("");
		ss3.clear();
		ss4 << storeReports[i].blk_Write_S;
		string write_S = ss4.str();
		ss4.str("");
		ss4.clear();
		ss5 << storeReports[i].kb_Write_S;\
		string kb_write = ss5.str();
		ss5.str("");
		ss5.clear();
		madeName << storeReports[i].device << "\t";
		if (conf.blk_Read_Conf == 1) {
			madeName << read << "\t";
		}
		else {
			madeName << "N/A" << "\t";
		}
		if (conf.blk_Read_S_Conf == 1) {
			madeName << read_S << "\t   ";
		}
		else {
			madeName << "N/A" << "\t   ";
		}
		if (conf.kb_Read_S_Conf == 1) {
			madeName << kbRead << "\t     ";
		}
		else {
			madeName << "N/A" <<"\t\t";
		}
		if (conf.blk_Write_Conf == 1) {
			if (storeReports[i].blk_Write < 100) {
			madeName << write << "\t       ";
			}
			else {
				madeName << write << "\t";
			}
		}
		else {
			madeName << "N/A" << "\t";
		}
		if (conf.blk_Write_S_Conf == 1) {
			madeName << write_S << "\t   ";
		}
		else {
			madeName << "N/A" << "\t    ";
		}
		if (conf.kb_Write_Conf == 1) {
			madeName << kb_write << "\n";
		}
		else {
			madeName << "N/A" << "\n";
		}
	}
	madeName.close();
}


void Report::printReport() {
	string line;
	reportName.open((char*)conf.reportName.c_str());
	if (reportName.fail()) {
		cout << "No record found in '" << conf.reportName << "'\n";
	}
	while (getline(reportName, line)){
		cout << line << "\n";
	}
	reportName.close();
}
}
