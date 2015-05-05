#include "StudentPreProcessing.h"
#include "basetimer.h"

IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	BaseTimer basetimer;
	basetimer.start();


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
	basetimer.stop();
	std::ofstream myfile;
	myfile.open("tijd.txt", std::ofstream::ate);
	myfile << "tijds: " << basetimer.elapsedSeconds() << " tijd ms:" << basetimer.elapsedMilliSeconds() << "tijd us" << basetimer.elapsedMicroSeconds();
	myfile.close();
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