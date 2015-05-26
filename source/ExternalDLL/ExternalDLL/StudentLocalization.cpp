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
	bool first = true;


	Point2D<double> MouthCenterPoint = features.getFeature(Feature::FEATURE_MOUTH_CENTER).getPoints()[0];

	Point2D<double> ChinPoint = features.getFeature(Feature::FEATURE_CHIN).getPoints()[0];
	int range = MouthCenterPoint.getY() - ChinPoint.getY();
	Feature output = Feature(Feature::FEATURE_CHIN_CONTOUR);
	int degrees;
	int steps = 15;
	int lastdif;
	double correction = -1;
	int lastSteps=0;
	int vorigeX=0;
	for (int i = 0; i < 19; i++){
		bool ireg = false;
		
		if (i>9){ correction = 1; }
		else if (i < 9){ correction =0; }
		int checkX = MouthCenterPoint.getX();
		int checkY = MouthCenterPoint.getY();
		
		
		double gradenInRad = (-90+(i * 10)) *(PI/180);
		//coordY = distance * Math.sin(angleInRadians * (Math.PI/180));
		//coordX = distance * Math.cos(angleInRadians * (Math.PI / 180));
		//degrees * 180)/pi;    graden naar rad
		steps = startStep;
		Point2D<double> gevondenPunt;
		if (i != 9) {		//middelste kin punt weten we al als het goed is
			while (true){
				if (!first&&steps > startStep + 10){ std::cout << "Kan niks vinden";
				lastdif / i;
				ireg = true;


				//gevondenPunt.set(MouthCenterPoint.getX() + ((lastSteps+correction)* std::sin(gradenInRad)), MouthCenterPoint.getY() + ((lastSteps+correction) * std::cos(gradenInRad)));
				//gevondenPunt.set(MouthCenterPoint.getX() + ((lastSteps)* std::sin(gradenInRad)), MouthCenterPoint.getY() + ((lastSteps) * std::cos(gradenInRad)));
				gevondenPunt.set(MouthCenterPoint.getX() + ((lastSteps + correction)* std::sin(gradenInRad)), MouthCenterPoint.getY() + ((lastSteps + correction) * std::cos(gradenInRad)));
				steps = lastSteps + correction;
				break;
				}
				checkX = MouthCenterPoint.getX()+ (steps * std::sin(gradenInRad));
				checkY = MouthCenterPoint.getY()+(steps * std::cos(gradenInRad));
				Intensity pixel = image.getPixel(std::round(checkX), std::round(checkY));
				if (int(pixel) == 0){
					if (checkX - vorigeX <2){

						lastdif / i;
						ireg = true;
						gevondenPunt.set(MouthCenterPoint.getX() + ((lastSteps + correction)* std::sin(gradenInRad)), MouthCenterPoint.getY() + ((lastSteps + correction) * std::cos(gradenInRad)));
						steps = lastSteps + correction;
						break;
					
					}
					ireg=false;
					
					gevondenPunt.set(checkX, checkY); break; }
				steps++;
			}
			vorigeX = checkX;
			std::cout << gevondenPunt <<"\n";
			startStep = steps - 5;
		
			output.addPoint(Point2D<double>(gevondenPunt.x,gevondenPunt.y));

			
			first=false;
			if (ireg){
				
				startStep = steps-5;
				lastSteps = steps;


			}
			else{
				lastdif = lastSteps - steps;
				lastSteps = steps;
			
			}
		

		}
		else{ output.addPoint(ChinPoint); }
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