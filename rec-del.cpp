//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <thread>
using namespace std;

const int DELAY = 15; // secs
const int BITRATE = 44; // kbps
const int BSIZE = DELAY * BITRATE * 1000 / 8;
char buffer[BSIZE];
bool bufferIsFull = 0;
int pos = 0;

void saveRec() {
	ofstream outFile;
	outFile.open("outFile.mp3", ios::binary);

	int currPos = pos;

	if (bufferIsFull) {
		for (int i=currPos+1;i<BSIZE;++i) {
			outFile.write(buffer+i, 1);
		}
	}

	for (int i=0;i<currPos+1;++i) {
		outFile.write(buffer+i, 1);
	}

	outFile.close();
}

void takeInput() {
	while (true) {
		string line; 
		getline(cin,line);
		if (line == "s") {
			saveRec();
		}
	}
}

int main () {
	char* cmd = "ffmpeg -nostdin -loglevel panic -f pulse -i default -b:a 44k -f mp3 pipe: 2>/dev/null &";
	FILE* proc = popen(cmd, "r");

	thread inputThread(takeInput);

	//for (int k=0;k<10;++k) {
	for (int k=0;;++k) {
		if (k>0) bufferIsFull=1;
		for (pos=0;pos<BSIZE;++pos) {
			buffer[pos]=fgetc(proc);
		}
	}

	pclose(proc);
	inputThread.join();

	return 0;
}
