#pragma once
#include "opencv.h"
#include "../BasicFunctions.h"
#include "Block.h"

//#include "Convert.h"
void cv_Substract(cv::Mat* cv_img_frame, unsigned char& uc, cv::Mat* cv_img_prevFrame, cv::Mat* cv_img_substractFrame,
	unsigned int& pixelSum, unsigned int& pixelSumL, unsigned int& pixelSumR, sBlock& leftBlock, sBlock& rightBlock);