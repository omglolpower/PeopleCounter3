#pragma once
#include "Opencv.h"
#include "Block.h"
void showImages(
	cv::Mat& cv_img_frameShow, cv::Mat& cv_img_frame, cv::Mat& cv_img_substractFrame,
	cv::Rect& cv_draw_blockL, cv::Rect& cv_draw_blockR,
	bool& isL,
	bool& isR,
	unsigned char& peopleIn,
	unsigned char& peopleOut
);