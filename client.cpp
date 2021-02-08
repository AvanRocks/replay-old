#include <iostream>
#include "Record.h"
using namespace std;

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

int main () {
	Record rec;
	takeInput(rec);

	return 0;
}
