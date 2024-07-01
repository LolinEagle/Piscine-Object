#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <png.h>
#include <sstream>
#include <vector>

using namespace std;

struct Vector2{
	float	x;
	float	y;
};

class Graph{
private:
	vector<Vector2>	point;
public:
	Graph(void);
	~Graph();

	void	addPoint(float x, float y);
	void	addLine(float x1, float y1, float x2, float y2);
	void	addPointFromFile(const string &filepath);
	void	printPoint(void);
	void	printPointToPng(void);
};

Graph::Graph(void){
}

Graph::~Graph(){
}

void	Graph::addPoint(float x, float y){
	Vector2	vec2;
	vec2.x = x;
	vec2.y = y;
	point.push_back(vec2);
}

int		sqr(int x){
	return (x * x);
}

double	find_dist(int x1, int y1, int x2, int y2){
	return (sqrt(sqr(y2 - y1) + sqr(x2 - x1)));
}

void	Graph::addLine(float x1, float y1, float x2, float y2){
	double	dist = find_dist(x1, y1, x2, y2);
	float	difX = (x2 - x1) / dist;
	float	difY = (y2 - y1) / dist;
	for (double i = 0; i <= dist; i += 1.){
		Vector2	vec2;
		vec2.x = x1 + (difX * i);
		vec2.y = y1 + (difY * i);
		point.push_back(vec2);
	}
}

void	Graph::addPointFromFile(const string &filepath){
	ifstream	file(filepath.c_str());
	string		line;

	while (getline(file, line)){
		istringstream	iss(line);
		string			token;
		double			x, y;

		iss >> token;
		x = atof(token.c_str());
		iss >> token;
		y = atof(token.c_str());
		addPoint(x, y);
	}
}

void	Graph::printPoint(void){
	float	x = 0.f;
	float	y = 0.f;

	for (vector<Vector2>::iterator it = point.begin(); it != point.end(); it++){
		if (x < it->x) x = it->x;
		if (y < it->y) y = it->y;
	}

	int		maxX = static_cast<int>(x) + 2;
	int		maxY = static_cast<int>(y) + 2;
	char	tab[maxX][maxY];

	for (int ix = 0; ix < maxX; ix++){
		for (int iy = 0; iy < maxY; iy++)
			tab[ix][iy] = '.';
	}
	for (vector<Vector2>::iterator it = point.begin(); it != point.end(); it++)
		tab[static_cast<int>(round(it->x))][static_cast<int>(round(it->y))] = 'X';
	for (int iy = maxY - 1; iy >= 0; iy--){
		iy > 9 ? cout << iy : cout << ' ' << iy;
		for (int ix = 0; ix < maxX; ix++)
			cout << ' ' << tab[ix][iy];
		cout << endl;
	}
	cout << "  ";
	for (int ix = 0; ix < maxX; ix++)
		ix > 9 ? cout << ix : cout << ' ' << ix;
	cout << endl;
}

void    write_png(const char* filename, int width, int height, png_bytep buffer){
	FILE	*fp = fopen(filename, "wb");
	if (!fp){
		cerr << "Could not open file " << filename << " for writing." << endl;
		return ;
	}

	png_structp	png = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (!png){
		cerr << "Could not allocate write struct." << endl;
		fclose(fp);
		return ;
	}

	png_infop	info = png_create_info_struct(png);
	if (!info){
		cerr << "Could not allocate info struct." << endl;
		png_destroy_write_struct(&png, (png_infopp)NULL);
		fclose(fp);
		return ;
	}

	if (setjmp(png_jmpbuf(png))){
		cerr << "Error during png creation." << endl;
		png_destroy_write_struct(&png, &info);
		fclose(fp);
		return ;
	}
	png_init_io(png, fp);
	png_set_IHDR(png, info, width, height, 8, PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);
	png_write_info(png, info);

	png_bytep	row_pointers[height];
	for(int y = 0; y < height; y++)
		row_pointers[y] = buffer + y * width * 3;

	png_write_image(png, row_pointers);
	png_write_end(png, NULL);
	png_destroy_write_struct(&png, &info);
	fclose(fp);
}

void	Graph::printPointToPng(void){
	float	x = 0.f;
	float	y = 0.f;

	for (vector<Vector2>::iterator it = point.begin(); it != point.end(); it++){
		if (x < it->x) x = it->x;
		if (y < it->y) y = it->y;
	}

	int	maxX = static_cast<int>(x) + 2;
	int	maxY = static_cast<int>(y) + 2;
	int	tab[maxX][maxY];

	for (int ix = 0; ix < maxX; ix++){
		for (int iy = 0; iy < maxY; iy++)
			tab[ix][iy] = 0;
	}
	for (vector<Vector2>::iterator it = point.begin(); it != point.end(); it++)
		tab[static_cast<int>(round(it->x))][static_cast<int>(round(it->y))] = 1;

	unsigned char	image[maxX * maxY * 3];

	// Create an RGB image from the 2D array
	for(int y = 0; y < maxY; y++){
		for(int x = 0; x < maxX; x++){
			int index = (y * maxX + x) * 3;
			if (tab[y][x] == 1){
				image[index] = 255;		// Red
				image[index + 1] = 0;	// Green
				image[index + 2] = 0;	// Blue
			} else{
				image[index] = 255;		// Red
				image[index + 1] = 255;	// Green
				image[index + 2] = 255;	// Blue
			}
		}
	}
	write_png("output.png", maxX, maxY, image);
	cout << "PNG file created: output.png" << endl;
}

int	main(void){
	Graph	graph;

	graph.addPointFromFile("file");
	graph.addLine(0.f, 42.f, 42.f, 0.f);
	graph.printPoint();
	graph.printPointToPng();
	return (0);
}
