#include <Circle.hpp>
#include <Rectangle.hpp>
#include <Triangle.hpp>

double	calculatingArea(Shape& shapre){
	return (shapre.calculatingArea());
}

double	calculatingPerimeter(Shape& shapre){
	return (shapre.calculatingPerimeter());
}

int	main(void){
	Circle		circle(1.0);
	Rectangle	rectangle(0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0);
	Triangle	triangle(0.0, 0.0, 1.0, 0.0, 0.0, 1.0);

	cout << "Circle area : " << calculatingArea(circle) << endl;
	cout << "Circle perimeter : " << calculatingPerimeter(circle) << endl;
	cout << "Rectangle area : " << calculatingArea(rectangle) << endl;
	cout << "Rectangle perimeter : " << calculatingPerimeter(rectangle) << endl;
	cout << "Triangle area : " << calculatingArea(triangle) << endl;
	cout << "Triangle perimeter : " << calculatingPerimeter(triangle) << endl;
	return (0);
}
