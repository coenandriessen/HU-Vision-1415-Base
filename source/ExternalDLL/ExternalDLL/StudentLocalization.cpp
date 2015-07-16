#include "StudentLocalization.h"
#include <math.h>
#include "basetimer.h"

bool StudentLocalization::stepFindHead(const IntensityImage &image, FeatureMap &features) const {
	return false;
}

bool StudentLocalization::stepFindNoseMouthAndChin(const IntensityImage &image, FeatureMap &features) const {
	return false;
}
const double PI = 3.141592653589793238463;

/**
* Functie voor het berekenen van de kin contouren
*
* @param	const IntensityImage &image
* @param	FeatureMap &features
*
* @return	true
*/

bool StudentLocalization::stepFindChinContours(const IntensityImage &image, FeatureMap &features) const {
	// Maak een basetimer object om de tijd bij te houden dat de implementatie nodig heeft.
	BaseTimer basetimer;
	// Start de basetimer.
	basetimer.start();
	// test getal 
	int startStep = 15; 
	bool first = true;
	// Sla het middenpunt van de mond op.
	Point2D<double> MouthCenterPoint = features.getFeature(Feature::FEATURE_MOUTH_CENTER).getPoints()[0];
	// Sla het kin punt op.
	Point2D<double> ChinPoint = features.getFeature(Feature::FEATURE_CHIN).getPoints()[0];
	int range = MouthCenterPoint.getY() - ChinPoint.getY();
	// Object om kincountoer punten in op te slaan.
	Feature output = Feature(Feature::FEATURE_CHIN_CONTOUR);
	int degrees;
	int steps = 15;
	int lastdif;
	double correction = -1;
	int lastSteps = 0;
	int vorigeX = 0;
	// Bereken 20 punten van de kin.
	for (int i = 0; i < 19; i++)
	{
		bool ireg = false;
		if (i>9)
		{ 
			correction = 1; 
		}
		else if (i < 9)
		{ 
			correction =0;
		}
		// Sla middelpunt mond x op.
		int checkX = MouthCenterPoint.getX();
		// Sla middelpunt mond y op.
		int checkY = MouthCenterPoint.getY();
		double gradenInRad = (-90+(i * 10)) *(PI/180);
		steps = startStep;
		Point2D<double> gevondenPunt;
		// Middelste punt van de kin is als het goed is bekend. Dit is punt nummer 9 dus zal worden overgeslagen.
		if (i != 9) 
		{
			while (true)
			{
				if (!first&&steps > startStep + 10)
				{ 
					lastdif / i;
					ireg = true;
					gevondenPunt.set(MouthCenterPoint.getX() + ((lastSteps + correction)* std::sin(gradenInRad)), MouthCenterPoint.getY() + ((lastSteps + correction) * std::cos(gradenInRad)));
					steps = lastSteps + correction;
					break;
				}
				checkX = MouthCenterPoint.getX()+ (steps * std::sin(gradenInRad));
				checkY = MouthCenterPoint.getY()+(steps * std::cos(gradenInRad));
				Intensity pixel = image.getPixel(std::round(checkX), std::round(checkY));
				if (int(pixel) == 0)
				{
					if (checkX - vorigeX <2)
					{
						lastdif / i;
						ireg = true;
						gevondenPunt.set(MouthCenterPoint.getX() + ((lastSteps + correction)* std::sin(gradenInRad)), MouthCenterPoint.getY() + ((lastSteps + correction) * std::cos(gradenInRad)));
						steps = lastSteps + correction;
						break;
					}
					ireg=false;
					gevondenPunt.set(checkX, checkY); break; 
				}
				steps++;
			}
			vorigeX = checkX;
			std::cout << gevondenPunt <<"\n";
			startStep = steps - 5;
			output.addPoint(Point2D<double>(gevondenPunt.x,gevondenPunt.y));
			first=false;
			if (ireg)
			{
				startStep = steps-5;
				lastSteps = steps;
			}
			else
			{
				lastdif = lastSteps - steps;
				lastSteps = steps;
			}
		}
		else
		{ 
			output.addPoint(ChinPoint); 
		}
	}
	features.putFeature(output);
	basetimer.stop();
	std::ofstream myfile;
	myfile.open("tijd.txt", std::ofstream::ate);
	myfile << "Chincontours convert tijd in s: " << basetimer.elapsedSeconds() << " tijd ms:" << basetimer.elapsedMilliSeconds() << " tijd us" << basetimer.elapsedMicroSeconds();
	myfile.close();
	return true;
}

bool StudentLocalization::stepFindNoseEndsAndEyes(const IntensityImage &image, FeatureMap &features) const {
	return false;
}

bool StudentLocalization::stepFindExactEyes(const IntensityImage &image, FeatureMap &features) const {
	return false;
}