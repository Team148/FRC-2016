/*
 * Logger.h
 *
 *  Created on: Nov 6, 2016
 *      Author: justingriggs
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "Robot.h"

using namespace std;

class Logger {
public:
	Logger();
	Logger(string filename);
	void SetLogInterval(double period);  		//set the logging period in sec
	void CreateNewFile(string filename);		//create a new CSV log file
	void CloseFile();							//closes the current log file
	string CurrentDateTime();					//Returns the current date/time
	void AddtoBuffer(string name, string value);
	void WriteToFile(string name, string value);//write data to file manually
	void Log();									//format data and write to file from all subsystems pushing to it, called in periodic

	struct logkey {double timestamp; string name; string value;};//logkey is the data structure that hold each log entry.
	//logkey logbuffer[5000];
	queue<logkey> logbuffer;

private:
	string m_filepathbase = "/home/lvuser/";
	string m_filenamebase;
	ofstream m_filestream;
	int m_period;
	Timer* m_timer;



};


#endif /* LOGGER_H_ */