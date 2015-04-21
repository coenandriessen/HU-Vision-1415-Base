#include "RGBImageStudent.h"
#include <iostream>
RGBImageStudent::RGBImageStudent() : RGBImage(0,0) {
	//std::cout << "Default constructor \n";
//	int throwError = 0, e = 1 / throwError; //Throws error without the need to include a header
	this->set(0, 0);
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImage(other.getWidth(), other.getHeight())
{
	//std::cout << "Copy constructor \n";
	this->set(other.getWidth(), other.getHeight());
	for (int i = 0; i < other.pixelstorage.size();i++)
		{
		for (int ii = 0; ii < other.pixelstorage.size(); ii++){
			setPixel(i,ii,other.getPixel(i, ii));
		
		
		
		}
	
	
		}

}


RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height) {
	pixelstorage.resize(width+1);
	//std::cout << "Argument constructor ";
	for (int i = 0; i < width; i++){
		pixelstorage.at(i).resize(height+1);

	}
	//TODO: Initialize pixel storage DONE?
}

RGBImageStudent::~RGBImageStudent() {
	//int throwError = 0, e = 1 / throwError;
	//TODO: delete allocated objects DONE?
}

void RGBImageStudent::set(const int width, const int height) {
	//std::cout << "Set size" <<width << "Height" <<height;
	RGBImage::set(width, height);

	pixelstorage.resize(width+1);
	for (int i = 0; i < width;i++){
		pixelstorage.at(i).resize(height+1);

	}
	
	//TODO: resize or create a new pixel storage (Don't forget to delete the old storage)
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	RGBImage::set(other.getWidth(), other.getHeight());
	//int throwError = 0, e = 1 / throwError;
	pixelstorage= other.pixelstorage;
	//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	//std::cout << "X gevragd:" << x;
	//std::cout << "Y Gevraagd " << y << ".";
	//std::cout << "Size x:" << pixelstorage.size();
	//std::cout << "Size y:" << pixelstorage.at(x).size();

	//std::cout << pixelstorage.size();
	if (x >= this->getWidth()){ //Als de x te groot is
		this->set(x, getHeight());
	}
	if(y >= this->getHeight()){ // als de y te groot is
		this->set(getWidth(), y);
	
	
	
	}
	
	pixelstorage.at(x).at(y) = pixel;
	//TODO: no comment needed :)
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	int x = i%getWidth();
	int y = i / getWidth();
	setPixel(x, y, pixel);
}

RGB RGBImageStudent::getPixel(int x, int y) const {
//	int throwError = 0
	return pixelstorage.at(x).at(y);
	return 0;
}

RGB RGBImageStudent::getPixel(int i) const {
	int x = i%getWidth();
	int y = i / getWidth();
	return getPixel(x, y);
}