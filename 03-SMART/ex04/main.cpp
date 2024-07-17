#include <ILogger.hpp>

int	main(void){
	LoggerFile		file;
	file.write("English");

	filebuf	fb;
	fb.open("stream.out", ios::out);
	
	LoggerStream	stream(&fb);
	stream.write("or spanish ?");

	fb.close();
	return (0);
}
