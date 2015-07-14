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
			pixel = ((0.3f * rgb.r) + (0.59f*  rgb.g) + (0.11 * rgb.b));
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
	IntensityImage* product = new IntensityImageStudent(200, 200);
	float yScale = 200.0f / image.getHeight();
	float xScale = 200.0f / image.getWidth();
	for (auto Xcord = 0; Xcord < 200; ++Xcord)
	{
		for (auto Ycord = 0; Ycord < 200; ++Ycord)
		{
			Intensity pixel = image.getPixel(std::round(xScale* Xcord), std::round(yScale* Ycord));
			product->setPixel(Xcord, Ycord, pixel);


		}
	}

	std::cout << yScale << " " << xScale << "\n";
	return product;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	IntensityImage *product = new IntensityImageStudent(image.getWidth(), image.getHeight());
	int index = 0;
	unsigned char compare = 220;
	for (auto Xcord = 0; Xcord < image.getWidth(); ++Xcord)
	{
		for (auto Ycord = 0; Ycord < image.getHeight(); ++Ycord)
		{
			if (image.getPixel(Xcord, Ycord) > compare)
			{
				product->setPixel(Xcord, Ycord, 0);
			}
			else
			{
				product->setPixel(Xcord, Ycord, 255);
			}
		}
	}
	return product;

}