#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
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
	cerr << difX << endl;
	cerr << difY << endl;
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
		tab[static_cast<int>(it->x)][static_cast<int>(it->y)] = 'X';
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

int	main(void){
	Graph	graph;

	graph.addPointFromFile("file");
	graph.addLine(0.f, 42.f, 42.f, 0.f);
	graph.printPoint();
	return (0);
}
