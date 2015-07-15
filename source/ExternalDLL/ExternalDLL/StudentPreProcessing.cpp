#include "StudentPreProcessing.h"
#include "basetimer.h"

/**
* Functie voor het converteren van een afbeedling van rgb naar grijswaarde.
*
* @param const	RGBImage &image
*
* @return		output
*/

IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	// Maak een basetimer aan. De basetimer wordt gebruikt om de tijd bij te houden
	// die de implementatie gebruikt.
	BaseTimer basetimer;
	// Start de basetimer.
	basetimer.start();
	// Maak de output voor de afeelding aan.
	IntensityImageStudent * output = new IntensityImageStudent();
	// Set de hoogte en breedte van de output.
	output->set(image.getWidth(), image.getHeight());
	// Loop elke pixel van de afbeelding door.
	for (int i = 0; i < image.getWidth(); i++)
	{
		for (int ii = 0; ii < image.getHeight(); ii++)
		{
			// Maak pixel object aan.
			Intensity pixel;
			// Maak rgb object aan met de rgb waarde van de orginele afbeelding.
			RGB rgb = image.getPixel(i, ii);
			// Luma / Luminance formule voor omzetten van rbg naar grijswaarde.
			pixel = ((0.3f * rgb.r) + (0.59f*  rgb.g) + (0.11 * rgb.b));
			// Averaging formule voor omzetten van rbg naar grijswaarde.
			//pixel = ((rgb.r + rgb.g + rgb.b) / 3);
			// Luster formule voor omzetten van rbg naar grijswaarde.
			//pixel = ((std::min({ rgb.b, rgb.g, rgb.r })) + (std::max({ rgb.b, rgb.g, rgb.r })) / 2);
			// Set de outputpixel aan de nieuwe waarde.
			output->setPixel(i, ii, pixel);
		}
	}
	// Stop de timer
	basetimer.stop();
	// Schrijf de tijd dat nodig is geweest naar een output file.
	std::ofstream myfile;
	myfile.open("tijd.txt", std::ofstream::ate);
	myfile << "Luma convert tijd in s: " << basetimer.elapsedSeconds() << " tijd ms:" 
		<< basetimer.elapsedMilliSeconds() << " tijd us" << basetimer.elapsedMicroSeconds();
	myfile.close();
	return output;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return stepScaleImageFirstOrder(image);
}

IntensityImage * StudentPreProcessing::stepScaleImageZeroOrder(const IntensityImage &image) const {
	IntensityImage* product = new IntensityImageStudent(200, 200);
	float yScale = image.getHeight() / 200.0f;
	float xScale = image.getWidth() / 200.0f;
	for (auto Xcord = 0; Xcord < 200; ++Xcord)
	{
		for (auto Ycord = 0; Ycord < 200; ++Ycord)
		{
			//std::cout << xScale* Xcord << " " << yScale* Ycord << "\n";
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

IntensityImage * StudentPreProcessing::stepScaleImageFirstOrder(const IntensityImage &image) const {
	IntensityImage* product = new IntensityImageStudent(200, 200);
	float yScale = image.getHeight() / 200.0f;
	float xScale = image.getWidth() / 200.0f;
	for (auto Xcord = 0; Xcord < 200; ++Xcord)
	{
		for (auto Ycord = 0; Ycord < 200; ++Ycord)
		{
			//std::cout << xScale* Xcord << " " << yScale* Ycord << "\n";
			Intensity pixel1 = image.getPixel(std::floor(xScale* Xcord), std::floor(yScale* Ycord));
			Intensity pixel2 = image.getPixel(std::floor(xScale* Xcord), std::ceil(yScale* Ycord));
			Intensity pixel3 = image.getPixel(std::ceil(xScale* Xcord), std::floor(yScale* Ycord));
			Intensity pixel4 = image.getPixel(std::ceil(xScale* Xcord), std::ceil(yScale* Ycord));
			Intensity pixel = (pixel1 + pixel2 + pixel3 + pixel4) / 4;
			product->setPixel(Xcord, Ycord, pixel);
		}
	}
	std::cout << yScale << " " << xScale << "\n";
	return product;
}
