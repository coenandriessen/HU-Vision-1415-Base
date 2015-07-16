#include "StudentPreProcessing.h"
#include "basetimer.h"


const int Guassian_filter[5][5] =
{
	{ 2, 4, 5, 4, 2 },
	{ 4, 9, 12, 9, 4 },
	{ 5, 12, 15, 12, 5 },
	{ 4, 9, 12, 9, 4 },
	{ 2, 4, 5, 4, 2 }
};

const int sobel_x[9][9] =
{
	{ 0, 0, 0,1,1,1,0,0,0},
	{ 0, 0, 0, 1, 1, 1, 0, 0, 0 },
	{ 0, 0, 0, 1, 1, 1, 0, 0, 0 },

	{ 1, 1, 1, -4, -4, -4, 1, 1, 1 },
	{ 1, 1, 1, -4, -4, -4, 1, 1, 1 },
	{ 1, 1, 1, -4, -4, -4, 1, 1, 1 },

	{ 0, 0, 0, 1, 1, 1, 0, 0, 0 },
	{ 0, 0, 0, 1, 1, 1, 0, 0, 0 },
	{ 0, 0, 0, 1, 1, 1, 0, 0, 0 }

};
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
	stepScaleImageZeroOrder(image);
	return stepScaleImageFirstOrder(image);
}

IntensityImage * StudentPreProcessing::stepScaleImageZeroOrder(const IntensityImage &image) const {
	BaseTimer basetimer;
	basetimer.start();
	std::cout << "scale";
	double scale;
	if (image.getHeight()*image.getWidth() > 200 * 200){ scale = sqrt(200 * 200 / static_cast<double>(image.getWidth() * image.getHeight())); }
	else{ scale = sqrt(image.getWidth() * image.getHeight() / static_cast<double>(image.getWidth() * image.getHeight())); }

		IntensityImage* product = new IntensityImageStudent(image.getWidth()*scale, image.getWidth()*scale);

		for (auto Xcord = 0; Xcord < image.getWidth()*scale; ++Xcord)
	{
			for (auto Ycord = 0; Ycord < image.getWidth()*scale; ++Ycord)
		{
			//std::cout << xScale* Xcord << " " << yScale* Ycord << "\n";
				Intensity pixel = image.getPixel(std::round(scale* Xcord), std::round(scale* Ycord));
			product->setPixel(Xcord, Ycord, pixel);
		}
	}
		basetimer.stop();
		std::ofstream myfile;
		myfile.open("tijdZeroOrderScale.txt", std::ofstream::ate);
		myfile << "Zero Order Scale convert tijd in s: " << basetimer.elapsedSeconds() << " tijd ms:" << basetimer.elapsedMilliSeconds() << " tijd us" << basetimer.elapsedMicroSeconds();
		myfile.close();
	return product;

	


}


IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	// Maak de output voor de afeelding aan.
	
	IntensityImage * output = new IntensityImageStudent(image.getHeight(), image.getWidth());
	// Set de hoogte en breedte van de output afbeelding.
	
	//IntensityImageStudent * henk = stepThresholding(image);
	
	// Maak variabele aan voor opslaan van pixel waarde.
	//output->set(image.getWidth() - 1, image.getHeight() - 1);
	// sobel

	for (int Xcord = 5; Xcord < image.getWidth()-5; Xcord++)
	{
		for (int Ycord = 5; Ycord < image.getHeight()-5; Ycord++)
		{
			int weight = 0;
			for (int i = -4; i < 5; i++){
				for (int j = -4; j<5; j++){
					int pixelvalue = static_cast<int>(image.getPixel(i + Xcord, j + Ycord));
					int sobelvalue = sobel_x[i + 4][j + 4];
					weight = weight + (pixelvalue * sobelvalue);
				}
			}
			int val = weight;
			if (val<0){ val = 0; }
			if (val>255){ val = 221; }
			output->setPixel(Xcord, Ycord, val);
		}
	}
	return output;
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
	BaseTimer basetimer;
	basetimer.start();
	double scale;
	if (image.getHeight()*image.getWidth() > 200 * 200){ scale = sqrt(200 * 200 / static_cast<double>(image.getWidth() * image.getHeight())); }
	else{ scale = sqrt(image.getWidth() * image.getHeight() / static_cast<double>(image.getWidth() * image.getHeight())); }
		IntensityImage* product = new IntensityImageStudent(image.getWidth()*scale, image.getHeight()*scale);

		for (auto Xcord = 0; Xcord < product->getWidth(); ++Xcord)
	{
			for (auto Ycord = 0; Ycord < product->getHeight(); ++Ycord)
		{
				Intensity pixel1 = image.getPixel(std::floor(Xcord * (1 / scale)), std::floor(Ycord * (1 / scale)));
				Intensity pixel2 = image.getPixel(std::floor(Xcord * (1 / scale)), std::ceil(Ycord * (1 / scale)));
				Intensity pixel3 = image.getPixel(std::ceil(Xcord * (1 / scale)), std::floor(Ycord * (1 / scale)));
				Intensity pixel4 = image.getPixel(std::ceil(Xcord * (1 / scale)), std::ceil(Ycord * (1 / scale)));



			Intensity pixel = (pixel1 + pixel2 + pixel3 + pixel4) / 4;
			product->setPixel(Xcord, Ycord, pixel);
		}
	}
		std::ofstream myfile;
		myfile.open("tijdFirstOrderScale.txt", std::ofstream::ate);
		myfile << "First Order Scale convert tijd in s: " << basetimer.elapsedSeconds() << " tijd ms:" << basetimer.elapsedMilliSeconds() << " tijd us" << basetimer.elapsedMicroSeconds();
		myfile.close();
	return product;

}



