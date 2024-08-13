#include <City.hpp>

void	City::addRail(Rail* rail){
    if (find(_rails.begin(), _rails.end(), rail) == _rails.end())
        _rails.push_back(rail);
}
