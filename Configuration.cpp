// Name: Adedotun Odutola
// userID: aco0008
// File Name: Configuration.cpp
// Mac Terminal Make file compiler was used.


#include "Configuration.h"
namespace auDisk {
Configuration::Configuration() {
	fileName = "disktool.conf";
	reportName ="report.adt";
	ReadConf();
}




void Configuration::ReadConf() {
		confFile.open((char*)fileName.c_str());
		if (confFile.fail()) {
			interval = 5;
			count = 10;
			blk_Read_Conf = 1;
			blk_Read_S_Conf = 1;
			kb_Read_S_Conf = 1;
			blk_Write_Conf = 0;
			blk_Write_Conf = 0;
			blk_Write_S_Conf = 0;
			kb_Write_Conf = 0;
		}
		else {
			while (!confFile.eof()) {
				confFile >> interval;
				confFile >> count;
				confFile >> blk_Read_Conf;
				confFile >> blk_Read_S_Conf;
				confFile >> kb_Read_S_Conf;
				confFile >> blk_Write_Conf;
				confFile >> blk_Write_S_Conf;
				confFile >> kb_Write_Conf;
			}
		}
}

void Configuration::printConf() {
	cout << "Monitoring time = " << interval << " seconds\n";
	cout << "Number of records = " << count << "\n";
	cout << "read = " << blk_Read_Conf << "\n";
	cout << "read/s = " << blk_Read_S_Conf << "\n";
	cout << "kb_read/s = " << kb_Read_S_Conf << "\n";
	cout << "write = " << blk_Write_Conf << "\n";
	cout << "blk_write/s = " << blk_Write_S_Conf << "\n";
	cout << "kb_write/s = " << kb_Write_Conf << "\n";
	cout << "report file name = ‘" << reportName << "'\n";
}

void Configuration::save() {;
		stringstream ss;
		stringstream ss1;
		stringstream ss2;
		stringstream ss3;
		stringstream ss4;
		stringstream ss5;
		stringstream ss6;
		stringstream ss7;
		ss << interval;
		string intervalS = ss.str();
		ss1 << count;
		string countS = ss1.str();
		ss2 << blk_Read_Conf;
		string blk_Read_ConfS = ss2.str();
		ss3 << blk_Read_S_Conf;
		string blk_Read_S_ConfS = ss3.str();
		ss4 << kb_Read_S_Conf;
		string kb_Read_S_ConfS = ss4.str();
		ss5 << blk_Write_Conf;
		string blk_Write_ConfS = ss5.str();
		ss6 << blk_Write_S_Conf;
		string blk_Write_S_ConfS = ss6.str();
		ss7 << kb_Write_Conf;
		string kb_Write_ConfS = ss7.str();
		confSave.open((char*)fileName.c_str());
		confSave << intervalS << " ";
		confSave << countS << " ";
		confSave << blk_Read_ConfS << " ";
		confSave << blk_Read_S_ConfS << " ";
		confSave << kb_Read_S_ConfS << " ";
		confSave << blk_Write_ConfS << " ";
		confSave << blk_Write_S_ConfS << " ";
		confSave << kb_Write_ConfS << " ";
		confSave.close();
		cout << "file disktool.conf has been updated.\n";
}
}
