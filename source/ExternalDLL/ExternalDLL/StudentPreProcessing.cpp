#include "StudentPreProcessing.h"


IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	IntensityImageStudent * output = new IntensityImageStudent();
	output->set(image.getWidth(), image.getHeight());
	for (int i = 0; i < image.getWidth(); i++){
		for (int ii = 0; ii < image.getHeight(); ii++){
			
			Intensity pixel;
			RGB rgb = image.getPixel(i, ii);
			pixel = (2 * rgb.r + 5 * rgb.g) / 7;
			output->setPixel(i, ii, pixel);
		
		
		
		
		}
	
	
	}
	return output;
	
}
IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}