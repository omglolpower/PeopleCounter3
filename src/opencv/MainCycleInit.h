#pragma once
#include "Opencv.h"
void mainCycleInit(cv::Mat& cv_img_prevFrame, cv::Mat& cv_img_frame, cv::VideoCapture& cv_vid_video,
	bool& wasL, bool& isL, bool& wasR, bool& isR,
	unsigned int& pixelSum,
	unsigned int& pixelSumL,
	unsigned int& pixelSumR,
	unsigned char& uc,
	cv::Mat& cv_img_substractFrame
);