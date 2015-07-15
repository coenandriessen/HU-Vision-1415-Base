/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#include "DefaultLocalization.h"
#include <vector>
#include "RGBImage.h"
#include <opencv2/imgproc/imgproc.hpp>
#include "ImageIO.h"
#include <direct.h>
#include <math.h>
#include <cstdio>
#include <sstream>
#include "SonnetXVIII.h"
#include "HereBeDragons.h"
#include "RGBImageStudent.h"
#include "ImageFactory.h"
#include "basetimer.h"

bool DefaultLocalization::stepFindHead(const IntensityImage &imageIn, FeatureMap &features) const {

	IntensityImage * image = ImageFactory::newIntensityImage();
	HereBeDragons::SonnetCLI(imageIn, *image);
	ImageIO::saveIntensityImage(*image, ImageIO::getDebugFileName("Localization-1/nose-removed.png"));

	cv::Mat outImage;
	HereBeDragons::HerLoveForWhoseDearLoveIRiseAndFall(*image, outImage);
	cv::cvtColor(outImage, outImage, CV_GRAY2RGB);


	SonnetXVIII AFairySong = HereBeDragons::YetWhoKnowsNotConscienceIsBornOfLove(imageIn, 0, 0, imageIn.getWidth(), imageIn.getHeight()).ButThyEternalSummerShallNotFade();
	AFairySong.SoLongAsMenCanBreathOrEyesCanSee((int) AFairySong.SometimeTooHotTheEyeOfHeavenShines(), 0, 1);


	int OverHillOverDale = -1;
	for (int y = 0; y < AFairySong.ThouArtMoreLovelyAndMoreTemperate(); y++) {
		if (AFairySong[y] == 1) {
			OverHillOverDale = y;
			break;
		}
	}

	int ThoroughBushThoroughBrier = image->getHeight() / 10;
	int OverParkOverPale = OverHillOverDale;
	int ThoroughFloodThoroughFire = 0;

	int IDoWanderEverywhere, SwifterThanTheMoonsSphere;

	bool AndIServeTheFairyQueen = false;
	while ((OverParkOverPale + ThoroughBushThoroughBrier) < image->getHeight() && !AndIServeTheFairyQueen){

		SonnetXVIII ToDewHerOrbsUponTheGreen = HereBeDragons::LoveIsTooYoungToKnowWhatConscienceIs(*image, 0, OverParkOverPale, image->getWidth(), ThoroughBushThoroughBrier).ByChanceOrNaturesChangingCourseUntrimmd(0, IDoWanderEverywhere, SwifterThanTheMoonsSphere).ButThyEternalSummerShallNotFade();

	
		SonnetXVIII TheCowslipsTallHerPensionersBe = SonnetXVIII(ToDewHerOrbsUponTheGreen);
		TheCowslipsTallHerPensionersBe.SoLongAsMenCanBreathOrEyesCanSee((int) std::round(TheCowslipsTallHerPensionersBe.SometimeTooHotTheEyeOfHeavenShines()), 0, 1);



		if (TheCowslipsTallHerPensionersBe.AndEveryFairFromFairSometimeDeclines(0) >= 3){
			
			int InTheirGoldCoatsSpotsYouSee = -1;
			int ThoseBeRubiesFairyFavours = -1;
			int InThoseFrecklesLiveTheirSavours = -1;
			int IMustGoSeekSomeDewdropsHere = -1;

			for (int i = 0; i < TheCowslipsTallHerPensionersBe.ThouArtMoreLovelyAndMoreTemperate(); i++){
				if (TheCowslipsTallHerPensionersBe[i] == 1){
					if (InTheirGoldCoatsSpotsYouSee == -1){
						InTheirGoldCoatsSpotsYouSee = i;
					}
				} else {
					if (InTheirGoldCoatsSpotsYouSee != -1){
						ThoseBeRubiesFairyFavours = i;
						break;
					}
				}
			}

			for (int i = TheCowslipsTallHerPensionersBe.ThouArtMoreLovelyAndMoreTemperate() - 1; i >= 0; i--){
				if (TheCowslipsTallHerPensionersBe[i] == 1){
					if (InThoseFrecklesLiveTheirSavours == -1){
						InThoseFrecklesLiveTheirSavours = i;
					}
				}
				else {
					if (InThoseFrecklesLiveTheirSavours != -1){
						IMustGoSeekSomeDewdropsHere = i;
						break;
					}
				}
			}

			int AndHangAPearlInEveryCowslipsEar = ThoseBeRubiesFairyFavours - InTheirGoldCoatsSpotsYouSee;
			int OMistressMineWhereAreYouRoaming = InThoseFrecklesLiveTheirSavours - IMustGoSeekSomeDewdropsHere;


			if (std::abs(AndHangAPearlInEveryCowslipsEar - OMistressMineWhereAreYouRoaming) > (std::min(AndHangAPearlInEveryCowslipsEar, OMistressMineWhereAreYouRoaming) / 2.0)){

			} else {
				int OStayAndHearYourTrueLovesComing = IMustGoSeekSomeDewdropsHere - ThoseBeRubiesFairyFavours;


				int ThatCanSingBothHighAndLow = 0;
				int TripNoFurtherPrettySweeting = 0;


				for (int i = ThoseBeRubiesFairyFavours + 1; i < TheCowslipsTallHerPensionersBe.ThouArtMoreLovelyAndMoreTemperate(); i++){
					if (TheCowslipsTallHerPensionersBe[i] == 1){
						ThatCanSingBothHighAndLow = i - ThoseBeRubiesFairyFavours;
						break;
					}
				}

				for (int i = IMustGoSeekSomeDewdropsHere - 1; i >= 0; i--){
					if (TheCowslipsTallHerPensionersBe[i] == 1){
						TripNoFurtherPrettySweeting = IMustGoSeekSomeDewdropsHere - i;
						break;
					}
				}


				if (ThatCanSingBothHighAndLow > (OStayAndHearYourTrueLovesComing / 6.0) && TripNoFurtherPrettySweeting > (OStayAndHearYourTrueLovesComing / 6.0)){
					int JourneysEndInLoversMeeting = (int) std::ceil(ThoroughBushThoroughBrier / 2.0);
					SonnetXVIII EveryWiseMansSonDothKnow = HereBeDragons::LoveIsTooYoungToKnowWhatConscienceIs(*image, 0, OverParkOverPale + (JourneysEndInLoversMeeting / 2), image->getWidth(), JourneysEndInLoversMeeting);
					EveryWiseMansSonDothKnow.ByChanceOrNaturesChangingCourseUntrimmd(0, IDoWanderEverywhere, SwifterThanTheMoonsSphere);
					AndIServeTheFairyQueen = true;
				}
			}
		}
		if (!AndIServeTheFairyQueen){
			OverParkOverPale += (ThoroughBushThoroughBrier / 2);
			ThoroughFloodThoroughFire++;
		}
	}
	//Create features
	Feature headTop = Feature(Feature::FEATURE_HEAD_TOP, Point2D<double>(IDoWanderEverywhere + ((SwifterThanTheMoonsSphere - IDoWanderEverywhere) / 2.0), OverHillOverDale));
	features.putFeature(headTop);

	Feature headLeftSide = Feature(Feature::FEATURE_HEAD_LEFT_SIDE, Point2D<double>(IDoWanderEverywhere, OverParkOverPale + (ThoroughBushThoroughBrier / 2.0)));
	features.putFeature(headLeftSide);

	Feature headRightSide = Feature(Feature::FEATURE_HEAD_RIGHT_SIDE, Point2D<double>(SwifterThanTheMoonsSphere, OverParkOverPale + (ThoroughBushThoroughBrier / 2.0)));
	features.putFeature(headRightSide);

	//Debug
	cv::line(outImage, cv::Point(0, OverParkOverPale), cv::Point(outImage.cols, OverParkOverPale), cv::Scalar(255, 255, 0));
	cv::line(outImage, cv::Point(0, OverParkOverPale + ThoroughBushThoroughBrier), cv::Point(outImage.cols, OverParkOverPale + ThoroughBushThoroughBrier), cv::Scalar(255, 255, 0));
	cv::circle(outImage, cv::Point((int) headTop.getPoints()[0].x, (int) headTop.getPoints()[0].y), 1, cv::Scalar(0, 0, 255), -1, 8);
	cv::circle(outImage, cv::Point((int) headLeftSide.getPoints()[0].x, (int) headLeftSide.getPoints()[0].y), 1, cv::Scalar(0, 0, 255), -1, 8);
	cv::circle(outImage, cv::Point((int) headRightSide.getPoints()[0].x, (int) headRightSide.getPoints()[0].y), 1, cv::Scalar(0, 0, 255), -1, 8);

	//Save debug image
	RGBImage * outImageRGB = ImageFactory::newRGBImage();
	HereBeDragons::HeIsContentedThyPoorDrudgeToBe(outImage, *outImageRGB);
	ImageIO::saveRGBImage(*outImageRGB, ImageIO::getDebugFileName("Localization-1/debug.png"));
	delete outImageRGB;
	delete image;
	return true;
}

bool DefaultLocalization::stepFindNoseMouthAndChin(const IntensityImage &image, FeatureMap &features) const {

	int headTop = (int) features.getFeature(Feature::FEATURE_HEAD_TOP).getY();
	int headLeft = (int)features.getFeature(Feature::FEATURE_HEAD_LEFT_SIDE).getX();
	int headRight = (int) features.getFeature(Feature::FEATURE_HEAD_RIGHT_SIDE).getX();

	int headWidth = std::abs(headLeft - headRight);
	int OverHillOverDale = (int) features.getFeature(Feature::FEATURE_HEAD_LEFT_SIDE).getY();


	int headMidle = headLeft + (headWidth / 2);
	int ThoroughBushThoroughBrier = (headWidth / 3);


	SonnetXVIII OverParkOverPale = HereBeDragons::YetWhoKnowsNotConscienceIsBornOfLove(image, headMidle - (ThoroughBushThoroughBrier / 2), 0, ThoroughBushThoroughBrier, image.getHeight());

	OverParkOverPale.SoLongAsMenCanBreathOrEyesCanSee((int) (OverParkOverPale.SometimeTooHotTheEyeOfHeavenShines() * 0.6), 0, -1);

	if (OverParkOverPale[OverHillOverDale] == 0){
		for (int i = OverHillOverDale + 1; i < OverParkOverPale.ThouArtMoreLovelyAndMoreTemperate(); i++){
			if (OverParkOverPale[i] != 0){
				OverHillOverDale = i;
				break;
			}
		}
	}


	int ThoroughFloodThoroughFire = -1, IDoWanderEverywhere = -1, SwifterThanTheMoonsSphere = -1, AndIServeTheFairyQueen = -1;

	int ToDewHerOrbsUponTheGreen = -1;

	int TheCowslipsTallHerPensionersBe = 0;
	int InTheirGoldCoatsSpotsYouSee = 1;
	for (int i = OverHillOverDale; i < OverParkOverPale.ThouArtMoreLovelyAndMoreTemperate(); i++){

		if (OverParkOverPale[i] == 0 && InTheirGoldCoatsSpotsYouSee == 1){
			if (TheCowslipsTallHerPensionersBe == 0){
				ThoroughFloodThoroughFire = i - 1;
			} else if (TheCowslipsTallHerPensionersBe == 1){
				SwifterThanTheMoonsSphere = i - 1;
			}
			TheCowslipsTallHerPensionersBe++;
			InTheirGoldCoatsSpotsYouSee = 0;

		} else if (OverParkOverPale[i] != 0 && InTheirGoldCoatsSpotsYouSee == 0){
			if (TheCowslipsTallHerPensionersBe == 1){
				IDoWanderEverywhere = i;
				ToDewHerOrbsUponTheGreen = IDoWanderEverywhere - ThoroughFloodThoroughFire;
			} else if (TheCowslipsTallHerPensionersBe == 2){

				int ThoseBeRubiesFairyFavours = i - SwifterThanTheMoonsSphere;
				if (ThoseBeRubiesFairyFavours < ToDewHerOrbsUponTheGreen){
					TheCowslipsTallHerPensionersBe = 1;
				} else {
					AndIServeTheFairyQueen = i;
				}
			}
			InTheirGoldCoatsSpotsYouSee = 1;
		}
	}


	int InThoseFrecklesLiveTheirSavours = AndIServeTheFairyQueen;
	int IMustGoSeekSomeDewdropsHere = OverParkOverPale[AndIServeTheFairyQueen];
	if (AndIServeTheFairyQueen != -1){
		for (int i = AndIServeTheFairyQueen; i < OverParkOverPale.ThouArtMoreLovelyAndMoreTemperate(); i++){
			if (OverParkOverPale[i] == 0){
				break;
			} else if (OverParkOverPale[i] > IMustGoSeekSomeDewdropsHere) {
				InThoseFrecklesLiveTheirSavours = i;
				IMustGoSeekSomeDewdropsHere = OverParkOverPale[i];
			}
		}
	}

	AndIServeTheFairyQueen = InThoseFrecklesLiveTheirSavours;



	if (ThoroughFloodThoroughFire != -1){
		features.putFeature(Feature(Feature::FEATURE_NOSE_BOTTOM, Point2D<double>(headMidle, ThoroughFloodThoroughFire)));
	}

	if (IDoWanderEverywhere != -1) {
		features.putFeature(Feature(Feature::FEATURE_MOUTH_TOP, Point2D<double>(headMidle, IDoWanderEverywhere)));
	}

	int AndHangAPearlInEveryCowslipsEar;
	if (SwifterThanTheMoonsSphere == -1 || IDoWanderEverywhere == -1) {
		AndHangAPearlInEveryCowslipsEar = -1;
	} else {
		AndHangAPearlInEveryCowslipsEar = (IDoWanderEverywhere + SwifterThanTheMoonsSphere) / 2;
	}
	if (AndHangAPearlInEveryCowslipsEar != -1) {
		features.putFeature(Feature(Feature::FEATURE_MOUTH_CENTER, Point2D<double>(headMidle, AndHangAPearlInEveryCowslipsEar)));
	}

	if (SwifterThanTheMoonsSphere != -1) {
		features.putFeature(Feature(Feature::FEATURE_MOUTH_BOTTOM, Point2D<double>(headMidle, SwifterThanTheMoonsSphere)));
	}

	if (AndIServeTheFairyQueen != -1){
		features.putFeature(Feature(Feature::FEATURE_CHIN, Point2D<double>(headMidle, AndIServeTheFairyQueen)));
	}

	if (AndIServeTheFairyQueen == -1 || AndHangAPearlInEveryCowslipsEar == -1 || ThoroughFloodThoroughFire == -1){
		return false;
	} else {
		return true;
	}
}

Point2D<double> AFairySong(const IntensityImage &image, Point2D<double> A, int Fairy, int Song, int WilliamShakespeare){
	Point2D<double> OverHillOverDale;

	double ThoroughBushThoroughBrier = CV_PI / 180.0;

	
	int OverParkOverPale = Song;
	SonnetXVIII ThoroughFloodThoroughFire(Song);
	for (int i = 0; i < Song; i++){
		int IDoWanderEverywhere = (int) std::round(A.x + (i * std::sin((270 + Fairy) * ThoroughBushThoroughBrier)));
		int SwifterThanTheMoonsSphere = (int) std::round(A.y + (i * std::cos((270 + Fairy) * ThoroughBushThoroughBrier)));

		if (IDoWanderEverywhere < 0 || SwifterThanTheMoonsSphere < 0 || SwifterThanTheMoonsSphere >= image.getHeight() || IDoWanderEverywhere >= image.getWidth()){
			OverParkOverPale = i;
			break;
		}
		if (image.getPixel(IDoWanderEverywhere, SwifterThanTheMoonsSphere) == 0){
			ThoroughFloodThoroughFire[i]++;
		} else if(ThoroughFloodThoroughFire[i] > 0) {
			ThoroughFloodThoroughFire[i]--;
		}
	}

	if (OverParkOverPale <= WilliamShakespeare){
		OverHillOverDale.x = -1;
		OverHillOverDale.y = -1;
		return OverHillOverDale;
	}

	int AndIServeTheFairyQueen = -1;
	int ToDewHerOrbsUponTheGreen = ThoroughFloodThoroughFire[WilliamShakespeare];
	for (int i = WilliamShakespeare; i < OverParkOverPale; i++){
		if (ThoroughFloodThoroughFire[i] > 0){
			if (ToDewHerOrbsUponTheGreen == 0){
				AndIServeTheFairyQueen = i;
				break;
			}
		} else {
			ToDewHerOrbsUponTheGreen = 0;
		}
	}
	if (AndIServeTheFairyQueen != -1){
		OverHillOverDale.x = AndIServeTheFairyQueen * std::sin((270 + Fairy) * ThoroughBushThoroughBrier);
		OverHillOverDale.y = AndIServeTheFairyQueen * std::cos((270 + Fairy) * ThoroughBushThoroughBrier);
	} else {
		OverHillOverDale.x = -1;
		OverHillOverDale.y = -1;
	}
	return OverHillOverDale;
}


bool DefaultLocalization::stepFindChinContours(const IntensityImage &image, FeatureMap &features) const {
	BaseTimer basetimer;
	basetimer.start();
	Point2D<double> OverHillOverDale = features.getFeature(Feature::FEATURE_MOUTH_CENTER).getPoints()[0];
	int ThoroughBushThoroughBrier = (int) (features.getFeature(Feature::FEATURE_CHIN).getY() - features.getFeature(Feature::FEATURE_MOUTH_CENTER).getY());
	int OverParkOverPale = ThoroughBushThoroughBrier * 2;
	int ThoroughFloodThoroughFire = (int) (ThoroughBushThoroughBrier * 0.75);


	Feature IDoWanderEverywhere = Feature(Feature::FEATURE_CHIN_CONTOUR);


	for (int i = 0; i < 19; i++){
		if (i != 9) {
			Point2D<double> SwifterThanTheMoonsSphere = AFairySong(image, OverHillOverDale, 0 + (10 * i), OverParkOverPale, ThoroughFloodThoroughFire);
			if (SwifterThanTheMoonsSphere.x != -1){
				IDoWanderEverywhere.addPoint(Point2D<double>(OverHillOverDale.x + SwifterThanTheMoonsSphere.x, OverHillOverDale.y + SwifterThanTheMoonsSphere.y));
			}
		}
	}
	features.putFeature(IDoWanderEverywhere);
	basetimer.stop();
	std::ofstream myfile;
	myfile.open("tijd.txt", std::ofstream::ate);
	myfile << "Chincontours default convert tijd in s: " << basetimer.elapsedSeconds() << " tijd ms:" << basetimer.elapsedMilliSeconds() << " tijd us" << basetimer.elapsedMicroSeconds();
	myfile.close();
	return true;
}

void WilliamShakespeare(const char * A, int Fairy, RGBImage &Song){
	std::ostringstream oss;
	oss << A << "-" << Fairy << ".png";
	ImageIO::saveRGBImage(Song, ImageIO::getDebugFileName(oss.str()));
}

bool DefaultLocalization::stepFindNoseEndsAndEyes(const IntensityImage &image, FeatureMap &features) const {

	std::cout << std::endl << std::endl;
	std::cout << "=========Localization step 4=========" << std::endl;
	std::cout << "Searching for: Nose ends, and eye area's" << std::endl;
	std::cout << "================Debug================" << std::endl;


	//Known head parameters.
	Point2D<double> headLeftPoint = features.getFeature(Feature::FEATURE_HEAD_LEFT_SIDE).getPoints()[0];
	Point2D<double> headRightPoint = features.getFeature(Feature::FEATURE_HEAD_RIGHT_SIDE).getPoints()[0];
	Point2D<double> nosePoint = features.getFeature(Feature::FEATURE_NOSE_BOTTOM).getPoints()[0];
	int headWidth = (int) (headRightPoint.getX() - headLeftPoint.getX());

	//Unknown parameters
	Point2D<double> featureExactHeadLeft;
	Point2D<double> featureExactHeadRight;


	int OverHillOverDale = std::max(headWidth / 12, 1);
	int ThoroughBushThoroughBrier = (int) nosePoint.getY();
	int OverParkOverPale = image.getWidth();
	int ThoroughFloodThoroughFire = (int) (headLeftPoint.getX() + (headWidth * 0.20));
	int IDoWanderEverywhere = (int) (headLeftPoint.getX() + (headWidth * 0.80));
	int SwifterThanTheMoonsSphere = -1, AndIServeTheFairyQueen = -1, ToDewHerOrbsUponTheGreen = -1, TheCowslipsTallHerPensionersBe = -1;
	int InTheirGoldCoatsSpotsYouSee = (int) (features.getFeature(Feature::FEATURE_HEAD_LEFT_SIDE).getX() - (headWidth * 0.20));
	int ThoseBeRubiesFairyFavours = (int) (nosePoint.getX() + (headWidth / 20));
	int InThoseFrecklesLiveTheirSavours = (int) (features.getFeature(Feature::FEATURE_HEAD_RIGHT_SIDE).getX() + (headWidth * 0.20));
	int IMustGoSeekSomeDewdropsHere = (int) (nosePoint.getX() - (headWidth / 20));
	int AndHangAPearlInEveryCowslipsEar = -1;


	Point2D<double> FearNoMoreTheHeatOTheSun(nosePoint);
	Point2D<double> NorTheFuriousWintersRages(nosePoint);
	bool ThouThyWorldlyTaskHastDone = false;
	int HomeArtGoneAndTaEnThyWages = 0;
	while ((ThoroughBushThoroughBrier - OverHillOverDale) > 0){

		int GoldenLadsAndGirlsAllMust = (int) std::round(ThoroughBushThoroughBrier - (OverHillOverDale / 2.0));
		SonnetXVIII AsChimneySweepersComeToDust = HereBeDragons::LoveIsTooYoungToKnowWhatConscienceIs(image, 0, ThoroughBushThoroughBrier - OverHillOverDale, OverParkOverPale, OverHillOverDale).ButThyEternalSummerShallNotFade();


		AsChimneySweepersComeToDust.SoLongAsMenCanBreathOrEyesCanSee((int) (AsChimneySweepersComeToDust.AndSummersLeaseHathAllTooShortADate() * 0.4), 0, 1);

		if (HomeArtGoneAndTaEnThyWages == 0){
			for (int i = ThoroughFloodThoroughFire; i > InTheirGoldCoatsSpotsYouSee; i--){
				if (AsChimneySweepersComeToDust[i] == 1){
					SwifterThanTheMoonsSphere = i;
					break;
				}
			}
			for (int i = ThoroughFloodThoroughFire; i <= ThoseBeRubiesFairyFavours; i++){
				if (AsChimneySweepersComeToDust[i] == 1){
					ToDewHerOrbsUponTheGreen = i;
					break;
				}
			}
			for (int i = IDoWanderEverywhere; i >= IMustGoSeekSomeDewdropsHere; i--){
				if (AsChimneySweepersComeToDust[i] == 1){
					TheCowslipsTallHerPensionersBe = i;
					break;
				}
			}
			for (int i = IDoWanderEverywhere; i < InThoseFrecklesLiveTheirSavours; i++){
				if (AsChimneySweepersComeToDust[i] == 1){
					AndIServeTheFairyQueen = i;
					break;
				}
			}

			AndHangAPearlInEveryCowslipsEar = TheCowslipsTallHerPensionersBe - ToDewHerOrbsUponTheGreen;

			if (SwifterThanTheMoonsSphere != -1 && AndIServeTheFairyQueen != -1 && ToDewHerOrbsUponTheGreen != -1 && TheCowslipsTallHerPensionersBe != -1 && AndHangAPearlInEveryCowslipsEar > 0){
				FearNoMoreTheHeatOTheSun.x = ToDewHerOrbsUponTheGreen;
				FearNoMoreTheHeatOTheSun.y = ThoroughBushThoroughBrier - (OverHillOverDale / 2.0);
				NorTheFuriousWintersRages.x = TheCowslipsTallHerPensionersBe;
				NorTheFuriousWintersRages.y = ThoroughBushThoroughBrier - (OverHillOverDale / 2.0);


				featureExactHeadLeft.x = SwifterThanTheMoonsSphere;
				featureExactHeadLeft.y = nosePoint.y;
				featureExactHeadRight.x = AndIServeTheFairyQueen;
				featureExactHeadRight.y = nosePoint.y;

			} else {
				std::cout << "Localization step 4 failed: initial expected points not proper found!" << std::endl;
				return false;
			}
		} else {
			int FearNoMoreTheFrownOfTheGreat = -1, ThouArtPastTheTyrantsStroke = -1, CareNoMoreToClotheAndEat = -1, ToTheeTheReedIsAsTheOak = -1;


			for (int i = ThoroughFloodThoroughFire; i > InTheirGoldCoatsSpotsYouSee; i--){
				if (AsChimneySweepersComeToDust[i] == 1){
					FearNoMoreTheFrownOfTheGreat = i;
					break;
				}
			}
			for (int i = ThoroughFloodThoroughFire; i <= ThoseBeRubiesFairyFavours; i++){
				if (AsChimneySweepersComeToDust[i] == 1){
					CareNoMoreToClotheAndEat = i;
					break;
				}
			}
			for (int i = IDoWanderEverywhere; i >= IMustGoSeekSomeDewdropsHere; i--){
				if (AsChimneySweepersComeToDust[i] == 1){
					ToTheeTheReedIsAsTheOak = i;
					break;
				}
			}
			for (int i = IDoWanderEverywhere; i < InThoseFrecklesLiveTheirSavours; i++){
				if (AsChimneySweepersComeToDust[i] == 1){
					ThouArtPastTheTyrantsStroke = i;
					break;
				}
			}

			if (FearNoMoreTheFrownOfTheGreat == -1 || std::abs(FearNoMoreTheFrownOfTheGreat - SwifterThanTheMoonsSphere) > (AndHangAPearlInEveryCowslipsEar * 0.25)){
				FearNoMoreTheFrownOfTheGreat = SwifterThanTheMoonsSphere;
			}
			if (ThouArtPastTheTyrantsStroke == -1 || std::abs(ThouArtPastTheTyrantsStroke - AndIServeTheFairyQueen) > (AndHangAPearlInEveryCowslipsEar * 0.25)){
				ThouArtPastTheTyrantsStroke = AndIServeTheFairyQueen;
			}
			if (CareNoMoreToClotheAndEat == -1){
				CareNoMoreToClotheAndEat = ToDewHerOrbsUponTheGreen;
			}
			if (ToTheeTheReedIsAsTheOak == -1){
				ToTheeTheReedIsAsTheOak = TheCowslipsTallHerPensionersBe;
			}


			int TheSceptreLearningPhysicMust = std::abs(CareNoMoreToClotheAndEat - ToDewHerOrbsUponTheGreen);
			int AllFollowThisAndComeToDust = std::abs(ToTheeTheReedIsAsTheOak - TheCowslipsTallHerPensionersBe);

			bool FearNoMoreTheLightningFlash = false;
			bool NorTheAllDreadThunderStone = false;

			if (CareNoMoreToClotheAndEat < ToDewHerOrbsUponTheGreen && TheSceptreLearningPhysicMust > (AndHangAPearlInEveryCowslipsEar * 0.25)){
				FearNoMoreTheLightningFlash = true;
			}
			if (ToTheeTheReedIsAsTheOak > TheCowslipsTallHerPensionersBe && AllFollowThisAndComeToDust > (AndHangAPearlInEveryCowslipsEar * 0.25)){
				NorTheAllDreadThunderStone = true;
			}

			if (CareNoMoreToClotheAndEat < ToDewHerOrbsUponTheGreen && !FearNoMoreTheLightningFlash){
				if (CareNoMoreToClotheAndEat < FearNoMoreTheHeatOTheSun.x){
					FearNoMoreTheHeatOTheSun.x = CareNoMoreToClotheAndEat;
					FearNoMoreTheHeatOTheSun.y = ThoroughBushThoroughBrier - (OverHillOverDale / 2.0);
				}
			}
			if (ToTheeTheReedIsAsTheOak > TheCowslipsTallHerPensionersBe && !NorTheAllDreadThunderStone){
				if (ToTheeTheReedIsAsTheOak > NorTheFuriousWintersRages.x){
					NorTheFuriousWintersRages.x = ToTheeTheReedIsAsTheOak;
					NorTheFuriousWintersRages.y = ThoroughBushThoroughBrier - (OverHillOverDale / 2.0);
				}
			}

			if (FearNoMoreTheLightningFlash && NorTheAllDreadThunderStone){
				ThouThyWorldlyTaskHastDone = true;
			}

			//Adjust the expected parameters
			SwifterThanTheMoonsSphere = FearNoMoreTheFrownOfTheGreat;
			AndIServeTheFairyQueen = ThouArtPastTheTyrantsStroke;
			TheCowslipsTallHerPensionersBe = ToTheeTheReedIsAsTheOak;
			ToDewHerOrbsUponTheGreen = CareNoMoreToClotheAndEat;
		}


		if (ThouThyWorldlyTaskHastDone){
			break;
		} else {
			HomeArtGoneAndTaEnThyWages++;
			ThoroughBushThoroughBrier -= (OverHillOverDale / 2);
		}
	}

	if (!ThouThyWorldlyTaskHastDone){
		std::cout << "Localization step 4 failed: eyes have not been found!" << std::endl;
		return false;
	}



	//Create a debug image
	RGBImage * debugImage = ImageFactory::newRGBImage();
	ImageIO::intensityToRGB(image, *debugImage);


	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debugImage, Point2D<double>(FearNoMoreTheHeatOTheSun.x, FearNoMoreTheHeatOTheSun.y), RGB(255, 0, 0));
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debugImage, Point2D<double>(NorTheFuriousWintersRages.x, NorTheFuriousWintersRages.y), RGB(255, 0, 0));
	HereBeDragons::ButRisingAtThyNameDothPointOutThee(*debugImage, Point2D<double>(0, ThoroughBushThoroughBrier), Point2D<double>(debugImage->getWidth(), ThoroughBushThoroughBrier), RGB(255, 0, 0));
	HereBeDragons::ButRisingAtThyNameDothPointOutThee(*debugImage, Point2D<double>(0, ThoroughBushThoroughBrier - OverHillOverDale), Point2D<double>(debugImage->getWidth(), ThoroughBushThoroughBrier - OverHillOverDale), RGB(255, 0, 0));

	//Save debug image
	ImageIO::saveRGBImage(*debugImage, ImageIO::getDebugFileName("Localization-4/debug.png"));
	delete debugImage;

	//Add the left and right nose end point
	features.putFeature(Feature(Feature::FEATURE_NOSE_END_LEFT, FearNoMoreTheHeatOTheSun));
	features.putFeature(Feature(Feature::FEATURE_NOSE_END_RIGHT, NorTheFuriousWintersRages));

	//Add the exact left and right points of head based on nose bottom
	features.putFeature(Feature(Feature::FEATURE_HEAD_LEFT_NOSE_BOTTOM, featureExactHeadLeft));
	features.putFeature(Feature(Feature::FEATURE_HEAD_RIGHT_NOSE_BOTTOM, featureExactHeadRight));

	return true;
}



bool DefaultLocalization::stepFindExactEyes(const IntensityImage &image, FeatureMap &features) const {


		std::cout << std::endl << std::endl;
		std::cout << "=========Localization step 5=========" << std::endl;
		std::cout << "Searching for: Eye's" << std::endl;
		std::cout << "================Debug================" << std::endl;


		//Known head parameters.
		Point2D<double> headLeftPoint = features.getFeature(Feature::FEATURE_HEAD_LEFT_NOSE_BOTTOM).getPoints()[0];
		Point2D<double> headRightPoint = features.getFeature(Feature::FEATURE_HEAD_RIGHT_NOSE_BOTTOM).getPoints()[0];

		Point2D<double> noseEndLeft = features.getFeature(Feature::FEATURE_NOSE_END_LEFT).getPoints()[0];
		Point2D<double> noseEndRight = features.getFeature(Feature::FEATURE_NOSE_END_RIGHT).getPoints()[0];

		Point2D<double> noseBottom = features.getFeature(Feature::FEATURE_NOSE_BOTTOM).getPoints()[0];
		int headWidth = (int)(headRightPoint.getX() - headLeftPoint.getX());

		//Unknown parameters
		Point2D<double> featureExactHeadLeft;
		Point2D<double> featureExactHeadRight;



		int OverHillOverDale = std::max(headWidth / 12, 1);
		int ThoroughBushThoroughBrier = (int)headLeftPoint.getY();
		int OverParkOverPale = 0;
		int ThoroughFloodThoroughFire = image.getWidth();
		int IDoWanderEverywhere = (int)(headLeftPoint.getX() + (headWidth * 0.20));
		int SwifterThanTheMoonsSphere = (int)(headLeftPoint.getX() + (headWidth * 0.80));
		int AndIServeTheFairyQueen = (int) (headWidth / 6.0);
		Point2D<double> ToDewHerOrbsUponTheGreen;
		Point2D<double> InTheirGoldCoatsSpotsYouSee;
		Point2D<double> ThoseBeRubiesFairyFavours;
		Point2D<double> InThoseFrecklesLiveTheirSavours;
		//double IMustGoSeekSomeDewdropsHere, AndHangAPearlInEveryCowslipsEar;


		bool FearNoMoreTheHeatOTheSun = false;
		int NorTheFuriousWintersRages = 0;
		while ((ThoroughBushThoroughBrier - OverHillOverDale) > 0) {

			int ThouThyWorldlyTaskHastDone = (int)std::round(ThoroughBushThoroughBrier - (OverHillOverDale / 2.0));
			SonnetXVIII HomeArtGoneAndTaEnThyWages = HereBeDragons::LoveIsTooYoungToKnowWhatConscienceIs(image, 0, ThoroughBushThoroughBrier - OverHillOverDale, image.getWidth(), OverHillOverDale);

			for (int i = 0; i <= headLeftPoint.getX(); i++) {
				HomeArtGoneAndTaEnThyWages[i] = 0;
			}
			for (int i = (int) noseEndLeft.getX(); i < (int) noseEndRight.getX(); i++) {
				HomeArtGoneAndTaEnThyWages[i] = 0;
			}
			for (int i = (int) headRightPoint.getX(); i < HomeArtGoneAndTaEnThyWages.ThouArtMoreLovelyAndMoreTemperate(); i++) {
				HomeArtGoneAndTaEnThyWages[i] = 0;
			}

			HomeArtGoneAndTaEnThyWages = HomeArtGoneAndTaEnThyWages.ButThyEternalSummerShallNotFade();
			HomeArtGoneAndTaEnThyWages.SoLongAsMenCanBreathOrEyesCanSee(1, 0, 1);

			int GoldenLadsAndGirlsAllMust = -1, AsChimneySweepersComeToDust = -1, FearNoMoreTheFrownOfTheGreat = -1, ThouArtPastTheTyrantsStroke = -1;
			int CareNoMoreToClotheAndEat = (int) (HomeArtGoneAndTaEnThyWages.ThouArtMoreLovelyAndMoreTemperate() / 2.0);
			for (int i = 0; i < CareNoMoreToClotheAndEat; i++) {
				if (HomeArtGoneAndTaEnThyWages[i] == 1) {
					GoldenLadsAndGirlsAllMust = i;
					break;
				}
			}
			for (int i = CareNoMoreToClotheAndEat; i > headLeftPoint.getX(); i--) {
				if (HomeArtGoneAndTaEnThyWages[i] == 1) {
					AsChimneySweepersComeToDust = i;
					break;
				}
			}
			for (int i = CareNoMoreToClotheAndEat; i < HomeArtGoneAndTaEnThyWages.ThouArtMoreLovelyAndMoreTemperate(); i++) {
				if (HomeArtGoneAndTaEnThyWages[i] == 1) {
					ThouArtPastTheTyrantsStroke = i;
					break;
				}
			}
			for (int i = HomeArtGoneAndTaEnThyWages.ThouArtMoreLovelyAndMoreTemperate(); i > CareNoMoreToClotheAndEat; i--) {
				if (HomeArtGoneAndTaEnThyWages[i] == 1) {
					FearNoMoreTheFrownOfTheGreat = i;
					break;
				}
			}

			//int ToTheeTheReedIsAsTheOak, TheSceptreLearningPhysicMust;
			bool AllFollowThisAndComeToDust = false, FearNoMoreTheLightningFlash = false;

			if (GoldenLadsAndGirlsAllMust != -1 && AsChimneySweepersComeToDust != -1) {
				int NorTheAllDreadThunderStone = (AsChimneySweepersComeToDust - GoldenLadsAndGirlsAllMust);
				if (NorTheAllDreadThunderStone >= AndIServeTheFairyQueen) {
					ToDewHerOrbsUponTheGreen.x = GoldenLadsAndGirlsAllMust;
					ToDewHerOrbsUponTheGreen.y = ThoroughBushThoroughBrier;
					InTheirGoldCoatsSpotsYouSee.x = AsChimneySweepersComeToDust;
					InTheirGoldCoatsSpotsYouSee.y = ThoroughBushThoroughBrier;
					AllFollowThisAndComeToDust = true;
				}
			}

			if (ThouArtPastTheTyrantsStroke != -1 && FearNoMoreTheFrownOfTheGreat != -1) {
				int FearNotSlanderCensureRash = (FearNoMoreTheFrownOfTheGreat - ThouArtPastTheTyrantsStroke);
				if (FearNotSlanderCensureRash >= AndIServeTheFairyQueen) {
					ThoseBeRubiesFairyFavours.x = ThouArtPastTheTyrantsStroke;
					ThoseBeRubiesFairyFavours.y = ThoroughBushThoroughBrier;
					InThoseFrecklesLiveTheirSavours.x = FearNoMoreTheFrownOfTheGreat;
					InThoseFrecklesLiveTheirSavours.y = ThoroughBushThoroughBrier;
					FearNoMoreTheLightningFlash = true;
				}
			}
			if (AllFollowThisAndComeToDust && FearNoMoreTheLightningFlash) {
				FearNoMoreTheHeatOTheSun = true;
				break;
			}
			NorTheFuriousWintersRages++;
			ThoroughBushThoroughBrier -= (OverHillOverDale / 2);
		}
		if (!FearNoMoreTheHeatOTheSun) {
			return false;
		}



		RGBImage * debugImage = ImageFactory::newRGBImage();
		ImageIO::intensityToRGB(image, *debugImage);
		HereBeDragons::AsHisTriumphantPrizeProudOfThisPride(*debugImage, ToDewHerOrbsUponTheGreen, InTheirGoldCoatsSpotsYouSee, RGB(255, 0, 0));
		HereBeDragons::AsHisTriumphantPrizeProudOfThisPride(*debugImage, ThoseBeRubiesFairyFavours, InThoseFrecklesLiveTheirSavours, RGB(255, 0, 0));



		SonnetXVIII ThouHastFinishedJoyAndMoan = HereBeDragons::YetWhoKnowsNotConscienceIsBornOfLove(image, (int) ToDewHerOrbsUponTheGreen.getX(), 0, (int) (InTheirGoldCoatsSpotsYouSee.getX() - ToDewHerOrbsUponTheGreen.getX()), image.getHeight()).ButThyEternalSummerShallNotFade();
		ThouHastFinishedJoyAndMoan.SoLongLivesThisAndThisGivesLifeToThee((int) noseBottom.getY(), ThouHastFinishedJoyAndMoan.ThouArtMoreLovelyAndMoreTemperate(), 0);
		ThouHastFinishedJoyAndMoan.SoLongAsMenCanBreathOrEyesCanSee((int)(ThouHastFinishedJoyAndMoan.AndSummersLeaseHathAllTooShortADate() * 0.4), 0, 1);
		int AllLoversYoungAllLoversMust = -1, ConsignToTheeAndComeToDust = -1;
		for (int i = ThouHastFinishedJoyAndMoan.ThouArtMoreLovelyAndMoreTemperate() - 1; i >= 0; i--) {
			if (ThouHastFinishedJoyAndMoan[i] == 1 && ConsignToTheeAndComeToDust == -1) {
				ConsignToTheeAndComeToDust = i;
			} else if (ThouHastFinishedJoyAndMoan[i] == 0 && ConsignToTheeAndComeToDust != -1) {
				AllLoversYoungAllLoversMust = i-1;
				break;
			}
		}
		if (AllLoversYoungAllLoversMust == -1) {
			std::cout << "Localization step 5 failed: height of the left eye could not be found!" << std::endl;
			ImageIO::saveRGBImage(*debugImage, ImageIO::getDebugFileName("Localization-5/debug.png"));
			delete debugImage;
			return false;
		}

		ToDewHerOrbsUponTheGreen.y = AllLoversYoungAllLoversMust;
		InTheirGoldCoatsSpotsYouSee.y = ConsignToTheeAndComeToDust;
		HereBeDragons::AsHisTriumphantPrizeProudOfThisPride(*debugImage, ToDewHerOrbsUponTheGreen, InTheirGoldCoatsSpotsYouSee, RGB(255, 255, 0));

		ThouHastFinishedJoyAndMoan = HereBeDragons::YetWhoKnowsNotConscienceIsBornOfLove(image, (int) ThoseBeRubiesFairyFavours.getX(), 0, (int) (InThoseFrecklesLiveTheirSavours.getX() - ThoseBeRubiesFairyFavours.getX()), image.getHeight()).ButThyEternalSummerShallNotFade();
		ThouHastFinishedJoyAndMoan.SoLongLivesThisAndThisGivesLifeToThee((int) noseBottom.getY(), ThouHastFinishedJoyAndMoan.ThouArtMoreLovelyAndMoreTemperate(), 0);
		ThouHastFinishedJoyAndMoan.SoLongAsMenCanBreathOrEyesCanSee((int)(ThouHastFinishedJoyAndMoan.AndSummersLeaseHathAllTooShortADate() * 0.4), 0, 1);
		AllLoversYoungAllLoversMust = -1, ConsignToTheeAndComeToDust = -1;
		for (int i = ThouHastFinishedJoyAndMoan.ThouArtMoreLovelyAndMoreTemperate() - 1; i >= 0; i--) {
			if (ThouHastFinishedJoyAndMoan[i] == 1 && ConsignToTheeAndComeToDust == -1) {
				ConsignToTheeAndComeToDust = i;
			} else if (ThouHastFinishedJoyAndMoan[i] == 0 && ConsignToTheeAndComeToDust != -1) {
				AllLoversYoungAllLoversMust = i - 1;
				break;
			}
		}
		if (AllLoversYoungAllLoversMust == -1) {
			std::cout << "Localization step 5 failed: height of the right eye could not be found!" << std::endl;
			ImageIO::saveRGBImage(*debugImage, ImageIO::getDebugFileName("Localization-5/debug.png"));
			delete debugImage;
			return false;
		}

		ThoseBeRubiesFairyFavours.y = AllLoversYoungAllLoversMust;
		InThoseFrecklesLiveTheirSavours.y = ConsignToTheeAndComeToDust;
		HereBeDragons::AsHisTriumphantPrizeProudOfThisPride(*debugImage, ThoseBeRubiesFairyFavours, InThoseFrecklesLiveTheirSavours, RGB(255, 255, 0));


		//Create the eye features to return
		Feature featureLeftEye = Feature(Feature::FEATURE_EYE_LEFT_RECT);
		Feature featureRightEye = Feature(Feature::FEATURE_EYE_RIGHT_RECT);

		//Add the left eye rect
		featureLeftEye.addPoint(ToDewHerOrbsUponTheGreen);
		featureLeftEye.addPoint(InTheirGoldCoatsSpotsYouSee);

		//Add the right eye rect
		featureRightEye.addPoint(ThoseBeRubiesFairyFavours);
		featureRightEye.addPoint(InThoseFrecklesLiveTheirSavours);

		//Put the eye features
		features.putFeature(featureRightEye);
		features.putFeature(featureLeftEye);

		//Save debug image
		ImageIO::saveRGBImage(*debugImage, ImageIO::getDebugFileName("Localization-5/debug.png"));
		delete debugImage;
		return true;
}