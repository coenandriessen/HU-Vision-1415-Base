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
	int startStep = 15; // test getal 



	Point2D<double> MouthCenterPoint = features.getFeature(Feature::FEATURE_MOUTH_CENTER).getPoints()[0];

	Point2D<double> ChinPoint = features.getFeature(Feature::FEATURE_CHIN).getPoints()[0];
	int range = MouthCenterPoint.getY() - ChinPoint.getY();
	Feature output = Feature(Feature::FEATURE_CHIN_CONTOUR);
	int degrees;
	int steps = 15;

	for (int i = 0; i < 19; i++){
		int checkX = MouthCenterPoint.getX();
		int checkY = MouthCenterPoint.getY();
		double gradenInRad = (90-(i * 10)) *(PI/180);
		//coordY = distance * Math.sin(angleInRadians * (Math.PI/180));
		//coordX = distance * Math.cos(angleInRadians * (Math.PI / 180));
		//degrees * 180)/pi;    graden naar rad 
		steps = startStep;
		std::cout << "Nieuw Punt";
		Point2D<double> gevondenPunt;
		if (i != 9) {		//middelste kin punt weten we al als het goed is
			while (true){
				
				checkX = MouthCenterPoint.getX()+ (steps * std::sin(gradenInRad));
				checkY = MouthCenterPoint.getY()+(steps * std::cos(gradenInRad));

				std::cout << checkX << " " << checkY;
				Intensity pixel = image.getPixel(std::round(checkX), std::round(checkY));


				std::cout << "STEP " <<steps<<"PIXEL :" << int(pixel) << "\n";
				if (int(pixel)==0){ break; }
				steps++;
			}
			//std::cout << checkX << " " << checkY << "\n";
			startStep = steps - 5;
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