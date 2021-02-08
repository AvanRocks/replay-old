#include <iostream>
#include <unistd.h>
#include <getopt.h>
#include "Record.h"
using namespace std;

void usage(char* cmd) {
	printf("Usage: %s [-b bitrate (kHz)] [-d delay (sec)]\n", cmd);
	exit(1);
}

void invalidValue(char opt, char* cmd) {
	printf("Invalid value for option -%c\n", opt);
	usage(cmd);
}

int optToInt(char opt, char* cmd) {
	int val;

	try {
		val = stoi(optarg);
	} catch (invalid_argument& e) {
		usage(cmd);
	} catch (out_of_range& e) {
		invalidValue(opt,cmd);
	}

	return val;
}

int validateIntOpt(char opt, int low, int high, char* cmd) {
	int val = optToInt(opt,cmd);

	if (!(val >= low && val <= high))
		invalidValue(opt,cmd);

	return val;
}

void takeInput(const Record& rec) {
	while (true) {
		string line; 
		getline(cin,line);
		if (line == "s") {
			rec.saveRecording();
		} else if (line == "q") {
			return;
		}
	}
}

struct option long_options[] = {
	{ "debug", no_argument, nullptr, 'g' }
};

int main (int argc, char* argv[]) {
	int option; 

	int bitrate = 50, delay = 30;
	bool debug = false;
	//while( (option = getopt(argc, argv, "b:d:")) != -1)  {  
	while( (option = getopt_long(argc, argv, "b:d:", long_options, nullptr)) != -1)  {  
		switch(option)  {  
			case 'b':
				bitrate = validateIntOpt('b', 32, 150, argv[0]);
				break;
			case 'd':
				delay = validateIntOpt('d', 1, 300, argv[0]);
				break;
			case 'g':
				debug = true;
				break;
			case '?':  
				usage(argv[0]);
				break;  
		}  
	}  

	Record rec(delay, bitrate, debug);
	takeInput(rec);

	return 0;
}
