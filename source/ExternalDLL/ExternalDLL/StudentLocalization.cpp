#include "StudentLocalization.h"
#include <math.h>
bool StudentLocalization::stepFindHead(const IntensityImage &image, FeatureMap &features) const {
	return false;
}

bool StudentLocalization::stepFindNoseMouthAndChin(const IntensityImage &image, FeatureMap &features) const {
	return false;
}
const double PI = 3.141592653589793238463;
bool StudentLocalization::stepFindChinContours(const IntensityImage &image, FeatureMap &features) const {
	Point2D<double> MouthCenterPoint = features.getFeature(Feature::FEATURE_MOUTH_CENTER).getPoints()[0];

	Point2D<double> ChinPoint = features.getFeature(Feature::FEATURE_CHIN).getPoints()[0];
	int range = MouthCenterPoint.getY() - ChinPoint.getY();
	Feature output = Feature(Feature::FEATURE_CHIN_CONTOUR);
	int degrees;
	for (int i = 0; i < 19; i++){
		double checkX = MouthCenterPoint.getX();
		double checkY = MouthCenterPoint.getY();
		int steps = 0;
		degrees = i * 10;
		double gradenInRad = ((i * 10) * 180) / PI;
		//coordY = distance * Math.sin(angleInRadians * (Math.PI/180));
		//coordX = distance * Math.cos(angleInRadians * (Math.PI / 180)); gevonden op de interwebsz xD
		//degrees * 180)/pi;    graden naar rad 

		Point2D<double> gevondenPunt;
		if (i != 9) {		//middelste kin punt weten we al als het goed is
			while (true){
				double xVerandering = steps * std::sin(gradenInRad * (PI / 180));
				double yVerandering = steps * std::cos(gradenInRad * (PI / 180));
				checkX = checkX*xVerandering;
				checkY = checkY*yVerandering;

				std::cout << checkX << " " << checkY;
				std::cout << xVerandering;
				std::cout <<image.getPixel(std::round(checkX), std::round(checkY));
			
			
			
				
				if (checkY == range){ break; }
				steps++;
			}
			output.addPoint(Point2D<double>(MouthCenterPoint.getX() + gevondenPunt.x, MouthCenterPoint.getY() + gevondenPunt.y));





		}
		
	}


	features.putFeature(output);
	return true;
}

bool StudentLocalization::stepFindNoseEndsAndEyes(const IntensityImage &image, FeatureMap &features) const {
	return false;
}

bool StudentLocalization::stepFindExactEyes(const IntensityImage &image, FeatureMap &features) const {


	return false;
}