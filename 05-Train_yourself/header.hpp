#pragma once

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

#define RESET	"\33[00m"
#define BLACK	"\33[30m"
#define RED		"\33[31m"
#define GREEN	"\33[32m"
#define YELLOW	"\33[33m"
#define BLUE	"\33[34m"
#define MAGENTA	"\33[35m"
#define CYAN	"\33[36m"
#define ENDL	RESET << endl;
#define MAX_RECURSIVE	16
#define MAX_SPEED		120.f

enum Event{
	Riot,
	PassengersDiscomfort,
};

using namespace std;
