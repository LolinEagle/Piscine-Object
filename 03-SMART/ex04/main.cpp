#include <ILogger.hpp>

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

	os.write("Test sentence 1\n");
	fs.write("Test sentence 2\n");
	osHeader.write("Test sentence 3\n");
	fsHeader.write("Test sentence 4\n");
	osDate.write("Test sentence 5\n");
	fsDate.write("Test sentence 6\n");
	fb.close();
	fbHeader.close();
	fbDate.close();
	return (0);
}
