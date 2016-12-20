// Name: Adedotun Odutola
// userID: aco0008
// File Name: Commandline.cpp
// Mac Terminal Make file compiler was used.


#include "Commandline.h"
namespace auDisk {
Commandline::Commandline() {

}

void Commandline::help() {
	cout << "run - run the monitoring tool.\n";
	cout << "initialize interval [value] – set sampling period to [value]\n";
	cout << "initialize count [value] – set the number of records to [value]\n";
	cout << "initialize report [name] – set report file name to [name]\n";
	cout << "initialize blk_read [0|1] – set print_blk_read to 0 or 1\n";
	cout << "initialize blk_read/s [0|1] – set print_blk_read/s to 0 or 1\n";
	cout << "initialize kb_read/s [0|1] – set print_kb_read/s to 0 or 1\n";
	cout << "initialize blk_write [0|1] – set print_blk_write to 0 or 1\n";
	cout << "initialize blk_write/s [0|1] – set print_blk_write/s to 0 or 1\n";
	cout << "initialize kb_write/s [0|1] – set print_kb_write to 0 or 1\n";
	cout << "print config – displays all the parameters\n";
	cout << "print report – open and display the report file\n";
	cout << "save progress – the configuration file audisktool.conf is up to date\n";
	cout << "exit - exit the tool.\n";
}

int Commandline::setInterval(int value) {
	cout << "The sampling interval has been changed to " << value << "\n";
	return value;
}

int Commandline::setCount(int value) {
	cout << "The number of records generated in each run has been changed to " << value << "\n";
	return value;
}

string Commandline::setReportName(string name) {
	cout << "The report name has been changed to " << name << "\n";
	cout << "Please make sure you report ends with an .adt extension\n";
	return name;
}

int Commandline::setBlk_Read(int value) {
	if (value > 1) {
		value = 0;
		cout << "your value was out of bounds, please try to set it again. Resetting the value to 0.\n";
	}
	else {
		cout << "The value has been changed to " << value << "\n";
	}
	return value;
}

int Commandline::setBlk_Read_S(int value) {
	if (value > 1) {
		value = 0;
		cout << "your value was out of bounds, please try to set it again. Resetting the value to 0.\n";
	}
	else {
		cout << "The value has been changed to " << value << "\n";
	}
	return value;
}

int Commandline::setKb_Read(int value) {
	if (value > 1) {
		value = 0;
		cout << "your value was out of bounds, please try to set it again. Resetting the value to 0.\n";
	}
	else {
		cout << "The value has been changed to " << value << "\n";
	}
	return value;
}

int Commandline::setBlk_Write(int value) {
	if (value > 1) {
		value = 0;
		cout << "your value was out of bounds, please try to set it again. Resetting the value to 0.\n";
	}
	else {
		cout << "The value has been changed to " << value << "\n";
	}
	return value;
}

int Commandline::setBlkWrite_S(int value) {
	if (value > 1) {
		value = 0;
		cout << "your value was out of bounds, please try to set it again. Resetting the value to 0.\n";
	}
	else {
		cout << "The value has been changed to " << value << "\n";
	}
	return value;
}

int Commandline::setKb_Write(int value) {
	if (value > 1) {
		value = 0;
		cout << "your value was out of bounds, please try to set it again. Resetting the value to 0.\n";
	}
	else {
		cout << "The value has been changed to " << value << "\n";
	}
	return value;
}
}
