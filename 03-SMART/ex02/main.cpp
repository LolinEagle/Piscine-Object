#include <vector>
#include <Circle.hpp>
#include <Rectangle.hpp>
#include <Triangle.hpp>

int	main(void){
	Circle		circle(1.0);
	Rectangle	rectangle(0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0);
	Triangle	triangle(0.0, 0.0, 1.0, 0.0, 0.0, 1.0);

	vector<Shape*>	shapes;
	shapes.push_back(&circle);
	shapes.push_back(&rectangle);
	shapes.push_back(&triangle);

	cout << "Circle area : " << shapes[0]->getArea() << endl;
	cout << "Circle perimeter : " << shapes[0]->getPerimeter() << endl;
	cout << "Rectangle area : " << shapes[1]->getArea() << endl;
	cout << "Rectangle perimeter : " << shapes[1]->getPerimeter() << endl;
	cout << "Triangle area : " << shapes[2]->getArea() << endl;
	cout << "Triangle perimeter : " <<  shapes[2]->getPerimeter() << endl;
	return (0);
}
