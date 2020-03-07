#include "MainCycleInit.h"

void mainCycleInit(cv::Mat& cv_img_prevFrame, cv::Mat& cv_img_frame, cv::VideoCapture& cv_vid_video, bool& wasL, bool& isL, bool& wasR, bool& isR, unsigned int& pixelSum, unsigned int& pixelSumL, unsigned int& pixelSumR, unsigned char& uc, cv::Mat& cv_img_substractFrame)

{
	cv_img_prevFrame = cv_img_frame.clone();

	cv_vid_video >> cv_img_frame;


	wasL = isL;
	wasR = isR;


	pixelSum = 0;
	pixelSumL = 0;
	pixelSumR = 0;
	uc = 0;
	cv_img_substractFrame = ZEROS(cv_img_frame);
}