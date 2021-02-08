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
		Record(int delay = 15, int bitrate = 44);
		~Record();
		void saveRecording() const;
};

#endif
