#pragma once

#include <fstream>
#include <iostream>

using namespace std;

class ILogger{
	virtual void	write(string) = 0;
};

class LoggerStream: public ILogger{
private:
	ostream	_os;
public:
	LoggerStream(streambuf* sb): _os(sb){}
	~LoggerStream(){}

	void	write(string str){
		_os << str;
	}
};

class LoggerFile: public ILogger{
private:
	filebuf	_fb;
public:
	LoggerFile(void){_fb.open("file.out", ios::out);}
	~LoggerFile(){_fb.close();}

	void	write(string str){
		LoggerStream	stream(&_fb);
		stream.write(str);
	}
};
