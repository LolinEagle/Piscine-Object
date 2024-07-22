#include <ILogger.hpp>
#include <vector>

int	main(void){
	filebuf	fb;
	fb.open("ostream.out", ios::out);
	filebuf	fbHeader;
	fbHeader.open("ostreamHeader.out", ios::out);
	filebuf	fbDate;
	fbDate.open("ostreamDate.out", ios::out);

	LoggerOstream		os(&fb);
	LoggerFstream		fs("fstream.out");
	LoggerOstreamHeader	osHeader(&fbHeader);
	LoggerFstreamHeader	fsHeader("fstreamHeader.out");
	LoggerOstreamDate	osDate(&fbDate);
	LoggerFstreamDate	fsDate("fstreamDate.out");

	vector<ILogger*>	iLoggers;
	iLoggers.push_back(&os);
	iLoggers.push_back(&fs);
	iLoggers.push_back(&osHeader);
	iLoggers.push_back(&fsHeader);
	iLoggers.push_back(&osDate);
	iLoggers.push_back(&fsDate);

	iLoggers[0]->write("Test sentence 1\n");
	iLoggers[1]->write("Test sentence 2\n");
	iLoggers[2]->write("Test sentence 3\n");
	iLoggers[3]->write("Test sentence 4\n");
	iLoggers[4]->write("Test sentence 5\n");
	iLoggers[5]->write("Test sentence 6\n");
	fb.close();
	fbHeader.close();
	fbDate.close();
	return (0);
}
