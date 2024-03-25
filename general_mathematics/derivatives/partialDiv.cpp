#include <iostream>

// Functional Library:	Function objects are objects specifically designed to be used with a syntax similar
// 						to that of functions. Instaces of std::function can store, copy, and invoke
// 						Callable target -- functions, lambda expressions, bind expressions, or other function
// 						objects, as well as pointers to member functions and pointers to data members.
#include <functional>
#include <cmath>

//	Approximate the partial derivative with respect to x
double partialDerivativeX(const std::function<double(double, double)>& f, double x, double y, double h){
	return (f(x + h, y) - f(x, y - h)) / (2 * h);
}

//	Approximate the partial derivative with respect to y
double partialDerivativeY(const std::function<double(double, double)>& f, double x, double y, double h){
	return (f(x, y + h) - f(x, y - h)) / (2 * h);
}

int main(){
	
	// Define the function for which we want to find partial derivatives
	auto function = [](double x, double y){
		return x * x + y * y;	//	Example function: f(x, y) = x^2 + y^2
	};

	double x = 1.0;	//	Point at which we want to fidn the derivative with respect to x
	double y = 2.0;	//	Point at which we want to find the derivative with respect to y
	double h = 0.01;//	Step size for approximation
	
	double derivativeX = partialDerivativeX(function, x, y, h);
	double derivativeY = partialDerivativeY(function, x, y, h);

	std::cout << "The partial derivative with respect to x is: " << derivativeX << std::endl;
	std::cout << "The partial derivative with respect to y is: " << derivativeY << std::endl;

	return 0;
}
