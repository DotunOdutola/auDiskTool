// Name: Adedotun Odutola
// userID: aco0008
// File Name: Tool.cpp
// Mac Terminal Make file compiler was used.


#include "Tool.h"


//struct devStats;
namespace auDisk {
Tool::Tool() {
	fileNameAll = "/proc/diskstats";
}

void Tool::run() {
	conf.printConf();
	cout << "Please wait...\n";
	cout << "\n";
	allDevicesFile.open((char*)fileNameAll.c_str());
	if (allDevicesFile.fail()) {
		cout << "Could not open /proc/diskstats\n";
	}
	while (!allDevicesFile.eof()) {
		allDevicesFile >> dev.decoy1;
		allDevicesFile >> dev.decoy2;
		allDevicesFile >> dev.devName;
		allDevicesFile >> dev.reads;
		allDevicesFile >> dev.readMerge;
		allDevicesFile >> dev.writes;
		allDevicesFile >> dev.secReading;
		allDevicesFile >> dev.mSecondsRead;
		allDevicesFile >> dev.writeCompleted;
		allDevicesFile >> dev.secWritting;
		allDevicesFile >> dev.mSecondWrite;
		allDevicesFile >> dev.currentI_O;
		allDevicesFile >> dev.mSecondsI_O;
		allDevicesFile >> dev.weightedI_O;
		dev.mSecondsRead = dev.mSecondsRead / 1000;
		dev.mSecondWrite = dev.mSecondWrite / 1000;
		dev.mSecondsI_O = dev.mSecondsI_O / 1000;
		if (dev.reads > 0) {
		stats.push_back(dev);
		}
	}
	allDevicesFile.close();
	usleep(conf.interval * 1000000);
	allDevicesFile.open((char*)fileNameAll.c_str());
	if (allDevicesFile.fail()) {
		cout << "Could not open /proc/diskstats\n";
	}
	while (!allDevicesFile.eof()) {
		allDevicesFile >> dev1.decoy1;
		allDevicesFile >> dev1.decoy2;
		allDevicesFile >> dev1.devName;
		allDevicesFile >> dev1.reads;
		allDevicesFile >> dev1.readMerge;
		allDevicesFile >> dev1.writes;
		allDevicesFile >> dev1.secReading;
		allDevicesFile >> dev1.mSecondsRead;
		allDevicesFile >> dev1.writeCompleted;
		allDevicesFile >> dev1.secWritting;
		allDevicesFile >> dev1.mSecondWrite;
		allDevicesFile >> dev1.currentI_O;
		allDevicesFile >> dev1.mSecondsI_O;
		allDevicesFile >> dev1.weightedI_O;
		dev1.mSecondsRead = dev1.mSecondsRead / 1000;
		dev1.mSecondWrite = dev1.mSecondWrite / 1000;
		dev1.mSecondsI_O = dev1.mSecondsI_O / 1000;
		if (dev1.reads > 0) {
		stats1.push_back(dev1);
		}
	}
	allDevicesFile.close();
	for (int i = 0; i < stats.size(); i++) {
		report.rep.device = stats[i].devName;
		if (conf.blk_Read_Conf == 1) {
		report.rep.blk_Read = stats1[i].reads - stats[i].reads;
		}
		if (conf.blk_Read_S_Conf == 1) {
		report.rep.blk_Read_S = report.rep.blk_Read / conf.interval;
		}
		if (conf.kb_Read_S_Conf == 1) {
		report.rep.kb_Read_S = (stats1[i].secReading - stats[i].secReading) / conf.interval;
		}
		if (conf.blk_Write_Conf == 1) {
		report.rep.blk_Write = stats1[i].writes - stats[i].writes;
		}
		if (conf.blk_Write_S_Conf == 1) {
		report.rep.blk_Write_S = report.rep.blk_Write / conf.interval;
		}
		if (conf.kb_Write_Conf == 1) {
		report.rep.kb_Write_S = (stats1[i].secWritting - stats[i].secWritting) / conf.interval;
		}
		report.storeReports.push_back(report.rep);
	}
	report.createReport();
	cout << "A file \"" << conf.reportName << "\" is updated.\n";
}

void Tool::toolInterface() {
	int i = 1;
	string input;
	string partInput;
	string partInput1;
	string partInput2;
	cout << "auDiskTool. Type ‘help’ to find more about commands\n";
		while (i == 1) {
		cout << ">";
		getline(cin, input);
		cout << "\n";
		stringstream ss(input);
		while(!ss.eof()) {
			ss >> partInput;
			ss >> partInput1;
			ss >> partInput2;
		}
		if (partInput == "help") {
			cmd.help();
		}
		if (partInput == "run") {
			run();
		}
		if (partInput == "set") {
			if (partInput1 == "interval") {
				int value = atoi(partInput2.c_str());
				conf.interval = cmd.setInterval(value);
			}
			if (partInput1 == "count") {
				int value = atoi(partInput2.c_str());
				conf.count = cmd.setCount(value);
			}
			if (partInput1 == "report") {
				conf.reportName = cmd.setReportName(partInput2);
			}
			if (partInput1 == "blk_read") {
				int value = atoi(partInput2.c_str());
				conf.blk_Read_Conf = cmd.setBlk_Read(value);
			}
			if (partInput1 == "blk_read/s") {
				int value = atoi(partInput2.c_str());
				conf.blk_Read_S_Conf = cmd.setBlk_Read_S(value);
			}
			if (partInput1 == "kb_read/s") {
				int value = atoi(partInput2.c_str());
				conf.kb_Read_S_Conf = cmd.setKb_Read(value);
			}
			if (partInput1 == "blk_write") {
				int value = atoi(partInput2.c_str());
				conf.blk_Write_Conf = cmd.setBlk_Write(value);
			}
			if (partInput1 == "blk_write/s") {
				int value = atoi(partInput2.c_str());
				conf.blk_Write_S_Conf = cmd.setBlkWrite_S(value);
			}
			if (partInput1 == "kb_write/s") {
				int value = atoi(partInput2.c_str());
				conf.kb_Write_Conf = cmd.setKb_Write(value);
			}
		}
		if (partInput == "print") {
			if (partInput1 == "conf") {
				conf.printConf();
			}
			if (partInput1 == "report") {
				report.printReport();
			}
		}
		if (partInput == "save") {
			conf.save();
		}
		if (partInput == "exit") {
			conf.save();
			exit(1);
		}
		cout << "\n";
	}
}

void Tool::testRun() {
    cout << endl;
	cout << "*** Testing run command ***\n";
    cout << endl;
	run();
	cout << "Run case has passed!!\n";
}

void Tool::testSetRun() {
    cout << endl;
	cout << "*** Testing Set ***\n";
    cout << endl;
	cout << "case 1: interval\n";
	conf.interval = cmd.setInterval(1);
	assert(conf.interval == 1);
	cout << "case 1 passed!\n";
	cout << "case 2: count\n";
	conf.count = cmd.setCount(1);
	assert(conf.count == 1);
	cout << "case2: passed!\n";
	cout << "case 3: blk_read\n";
	conf.blk_Read_Conf = cmd.setBlk_Read(1);
	assert(conf.blk_Read_Conf == 1);
	cout << "case 3 passed!\n";
	cout << "case 4: blk_read_s\n";
	conf.blk_Read_S_Conf = cmd.setBlk_Read_S(1);
	assert(conf.blk_Read_S_Conf == 1);
	cout << "case 4 passed!\n";
	cout << "case 5: kb_read_s\n";
	conf.kb_Read_S_Conf = cmd.setKb_Read(1);
	assert(conf.kb_Read_S_Conf == 1);
	cout << "case 5 passed!\n";
	cout << "case 6: blk_write\n";
	conf.blk_Write_Conf = cmd.setBlk_Write(1);
	assert(conf.blk_Write_Conf == 1);
	cout << "case 6 passed!\n";
	cout << "case 7: blk_write_s\n";
	conf.blk_Write_S_Conf = cmd.setBlkWrite_S(1);
	assert(conf.blk_Write_S_Conf == 1);
	cout << "case 7 passed\n";
	cout << "case 8: kb _write_s\n";
	conf.kb_Write_Conf = cmd.setKb_Write(1);
	assert(conf.kb_Write_Conf == 1);
	cout << "case 8 passed!\n";
}

void Tool::testprint() {
    cout << endl;
	cout << "*** Testing print ***\n";
    cout << endl;
	cout << "Case 1: test print conf\n";
	conf.printConf();
	cout << "Case 1 passed !\n";
	cout << "Case 2: test print report\n";
	report.printReport();
	cout << "Case 2 passed!\n";
}

void Tool::testSave() {
    cout << endl;
	cout << "*** Testing save ***\n";
    cout << endl;
	cout << "Printing correct conf\n";
	conf.printConf();
	cout << "setting interval to 20\n";
	conf.interval = cmd.setInterval(20);
	cout << "Testing the save part\n";
	conf.printConf();
	cout << "Test of save successful if interval changed to 20.\n";
}

void Tool::testHelp() {
    cout << endl;
	cout << "*** Testing Help. ***\n";
    cout << endl;
	cmd.help();
	cout << "Testing of help passed!\n";
}
}
