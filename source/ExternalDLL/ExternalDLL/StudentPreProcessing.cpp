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
	int index = 0;
	while (true){

		try{
			Intensity current = image.getPixel(index);
			if (current > 220){ Intensity pixel = Intensity(255); image.setPixel(index, index, &pixel); }
			else{ image.setPixel(index, Intensity(0)); }
			index++;



		}
		catch (const std::out_of_range& oor) { break; }
	}

}