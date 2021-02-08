#ifndef RECORD_H
#define RECORD_H

#include <string>
#include <thread>
#include <iostream>

class Record {
	private:
		int DELAY;   // seconds
		int BITRATE;  // kbps
		int BUFFER_SIZE;
		int pos = 0;
		bool bufferIsFull = 0;
		char* buffer;
		std::string ffmpegCmd;
		FILE* ffmpegProc;
		bool keepRecording = true;
		std::thread recordingThread;

		void recordIntoBuffer();
		static char* getTime();

	public:
		Record(int delay = 30, int bitrate = 50, bool debug = false);
		~Record();
		void saveRecording() const;
};

#endif
