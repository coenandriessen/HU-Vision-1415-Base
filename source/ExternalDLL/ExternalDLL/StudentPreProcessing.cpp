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

const int sobel_x[3][3] =
{
	{ -1, 0, 1},
	{ -2, 0, 2},
	{ -1, 0, 1}
};

const int sobel_y[3][3] =
{
	{ -1, -2, -1 },
	{ 0, 0, 0 },
	{ 1, 2, 1 }
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
	return stepScaleImageFirstOrder(image);
}

IntensityImage * StudentPreProcessing::stepScaleImageZeroOrder(const IntensityImage &image) const {
	std::cout << "scale";

	if (image.getHeight()*image.getWidth() > 200 * 200){

		auto scale = sqrt(200*200 / static_cast<double>(image.getWidth() * image.getHeight()));
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
	return product;
}
	else{ return new IntensityImageStudent(); }

}


IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	// Maak de output voor de afeelding aan.
	IntensityImageStudent * output = new IntensityImageStudent();
	// Set de hoogte en breedte van de output afbeelding.
	output->set(image.getWidth() - 1, image.getHeight() - 1);
	//IntensityImageStudent * henk = stepThresholding(image);
	/*
	// Maak variabele aan voor opslaan van pixel waarde.
	int temp_pixel;
	for (int y = 2; y < image.getWidth() - 2; y++)
	{
		for (int x = 2; x < image.getHeight() - 2; x++)
		{
			temp_pixel = 0;
			for (int yy = -2; yy < 3; yy++)
			{
				for (int xx = -2; xx < 3; xx++)
				{
					int pixel_value = image.getPixel(x + xx, y + yy);
					temp_pixel += pixel_value * Guassian_filter[xx + 2][yy + 2];
				}
			}
			output->setPixel(x - 2, y - 2, static_cast<int>(temp_pixel));
		}
	}
	*/

	// sobel
	int x_weight = 0;
	int y_weight = 0;
	for (int i = 0; i < image.getHeight() -1; i++)
	{
		for (int j = 0; j < image.getWidth() -1; j++)
		{
			for (int ii = 0; i < 4; i++)
			{
				for (int jj = 0; i < 4; jj++)
				{
					x_weight += image.getPixel(i, j) * sobel_x[ii][jj];
					y_weight += image.getPixel(i, j) * sobel_y[ii][jj];
				}
			}
			short val = abs(x_weight) + abs(y_weight);
			//make sure the pixel value is between 0 and 255 and add thresholds
			if (val>200)
				val = 255;
			else if (val<100)
				val = 0;
			int ans = 255 - (unsigned char)(val);
			output->setPixel(j, i, ans);
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
	std::cout << "scale";

	if (image.getHeight()*image.getWidth() > 200 * 200){

		double scale = sqrt(200 * 200 / static_cast<double>(image.getWidth() * image.getHeight()));
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

		std::cout << scale << " " << scale << "\n";
		std::cout << product->getHeight() << " " << product->getWidth();
		getchar();
	return product;
}
	else { std::cout << "fuck"; getchar(); }
}
