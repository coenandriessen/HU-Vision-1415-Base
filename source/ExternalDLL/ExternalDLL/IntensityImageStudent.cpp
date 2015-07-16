#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
	this->set(0, 0);
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {
	this->set(other.getWidth(), other.getHeight());
	for (int i = 0; i < other.pixelstorage.size(); i++)
	{
		for (int ii = 0; ii < other.pixelstorage.at(0).size(); ii++){
			setPixel(i, ii, other.getPixel(i, ii));



		}


	}
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
	pixelstorage.resize(width + 1);
	//std::cout << "Argument constructor ";
	for (int i = 0; i < width; i++){
		pixelstorage.at(i).resize(height + 1);

	}
	//TODO: Initialize pixel storage DONE?
}

IntensityImageStudent::~IntensityImageStudent() {
	//int throwError = 0, e = 1 / throwError;
	//TODO: delete allocated objects
}

void IntensityImageStudent::set(const int width, const int height) {
	//std::cout << "Set size" <<width << "Height" <<height;
	IntensityImage::set(width, height);

	pixelstorage.resize(width + 1);
	for (int i = 0; i < width; i++){
		pixelstorage.at(i).resize(height + 1);

	}

	//TODO: resize or create a new pixel storage (Don't forget to delete the old storage)
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {

	IntensityImage::set(other.getWidth(), other.getHeight());
	//int throwError = 0, e = 1 / throwError;
	pixelstorage = other.pixelstorage;
	//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	//std::cout << "X gevragd:" << x;
	//std::cout << "Y Gevraagd " << y << ".";
	//std::cout << "Size x:" << pixelstorage.size();
	//std::cout << "Size y:" << pixelstorage.at(x).size();

	//std::cout << pixelstorage.size();
	if (x >= this->getWidth()){ //Als de x te groot is
		this->set(x, getHeight());
	}
	if (y >= this->getHeight()){ // als de y te groot is
		this->set(getWidth(), y);



	}

	pixelstorage.at(x).at(y) = pixel;
	//TODO: no comment needed :)
}
void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	int x = i%getWidth();
	int y = i / getWidth();
	setPixel(x, y, pixel);
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	try{
		return pixelstorage.at(x).at(y);      
}
	catch (const std::out_of_range& oor) {
		throw std::out_of_range("out of image range");

	}
	
}
Intensity IntensityImageStudent::getPixel(int i) const {
	int x = i%getWidth();
	int y = i / getWidth();
	

	try{
		return getPixel(x, y);
	}
	catch (const std::out_of_range& oor) {
		throw std::out_of_range("out of image range");

	}
}
