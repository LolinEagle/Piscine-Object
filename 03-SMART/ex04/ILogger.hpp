#pragma once

#include <ctime>
#include <fstream>
#include <iostream>

using namespace std;

class ILogger{
	virtual void	write(string) = 0;
};

class AOstream: public ILogger{
protected:
	ostream	_os;
public:
	AOstream(streambuf* sb): _os(sb){}
};

class AFstream: public ILogger{
protected:
	fstream	_fs;
public:
	AFstream(const char* filename){_fs.open(filename, ios::out);}
};

class LoggerOstream: public AOstream{
public:
	LoggerOstream(streambuf* sb): AOstream(sb){}

	void	write(string str){_os << str;}
};

class LoggerFstream: public AFstream{
public:
	LoggerFstream(const char* filename): AFstream(filename){}

	void	write(string str){_fs << str;}
};

class LoggerOstreamHeader: public AOstream{
public:
	LoggerOstreamHeader(streambuf* sb): AOstream(sb){}

	void	write(string str){_os << "LoggerOstream: " << str;}
};

class LoggerFstreamHeader: public AFstream{
public:
	LoggerFstreamHeader(const char* filename): AFstream(filename){}

	void	write(string str){_fs << "LoggerFstream: " << str;}
};

class LoggerOstreamDate: public AOstream{
public:
	LoggerOstreamDate(streambuf* sb): AOstream(sb){}

	void	write(string str){
		time_t result = time(NULL);

		_os << asctime(localtime(&result)) << str;
	}
};

class LoggerFstreamDate: public AFstream{
public:
	LoggerFstreamDate(const char* filename): AFstream(filename){}

	void	write(string str){
		time_t result = time(NULL);

		_fs << asctime(localtime(&result)) << str;
	}
};
