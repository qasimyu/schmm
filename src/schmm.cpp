// ***************************************************************************
// schmm.cpp (c) 2019 Zhenhua Yu <qasim0208@163.com>
// Health Informatics Lab, Ningxia University
// All rights reserved.

#include <string>
#include <ctime>

#include "MyDefine.h"

int main(int argc, char *argv[]) {
	/*** record elapsed time ***/
	time_t start_t, end_t;
	long time_used;
	start_t = time(NULL);
	
	parser.parseArgs(argc, argv);	
	
	string subcmd = argv[1];
	if(subcmd.compare("prepareinputs") == 0) {
		genomedata.fetchInputs();
	}
	else { // call CNAs
		genomedata.LoadAndProcess();
		cnacaller.callCNAs();
	}
	
	end_t = time(NULL);
	time_used = end_t-start_t;
	int minutes = time_used/60;
	int seconds = time_used - minutes*60;
	cerr << "\nElapsed time: " << minutes << " minutes and " << seconds << " seconds!\n" << endl;
	
	return 0;
}
