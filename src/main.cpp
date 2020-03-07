#include <iostream>

#include "opencv/Opencv.h"
#include "opencv/Substract.h"
#include "opencv/Block.h"
#include "opencv/MainCycleInit.h"
#include "opencv/ShowImages.h"
#include "BasicFunctions.h"
#include "Count.h"

int main()
{
	
	auto cv_vid_video = new cv::VideoCapture("res/videos/video1.mp4");

	auto cv_img_frame			= new cv::Mat;
	auto cv_img_prevFrame		= new cv::Mat;
	auto cv_img_frameShow		= new cv::Mat;
	auto cv_img_substractFrame  = new cv::Mat;

	bool gotFirstFrame = false;
	bool gotPrevFrame = false;

	unsigned int pixelSum = 0;
	unsigned int pixelSumL = 0;
	unsigned int pixelSumR = 0;

	bool isL = false;
	bool isR = false;
	bool wasL = false;
	bool wasR = false;

	unsigned char peopleIn = 0;
	unsigned char peopleOut = 0;

	(*cv_vid_video) >> (*cv_img_frame);

	unsigned int lineX = cv_img_frame->cols / 100 * 42;
	unsigned int width = cv_img_frame->cols / 100 * 21;

	auto leftBlock  = new sBlock(lineX - width, cv_img_frame->rows / 10,
		width, cv_img_frame->rows / 2);

	auto rightBlock = new sBlock(*leftBlock);
	rightBlock->m_x *= 2;

	cv::Rect cv_draw_blockL = cv::Rect(leftBlock->m_x, leftBlock->m_y, leftBlock->m_a, leftBlock->m_b);
	cv::Rect cv_draw_blockR = cv::Rect(rightBlock->m_x, rightBlock->m_y, rightBlock->m_a, rightBlock->m_b);

	unsigned char uc = 0;

	while(1)
	{
		if (cv_img_frame->empty()) break;
		mainCycleInit(*cv_img_prevFrame, *cv_img_frame, *cv_vid_video, wasL, isL, wasR, isR,
			pixelSum,
			pixelSumL,
			pixelSumR,
			uc,
			*cv_img_substractFrame
		);

		cv_Substract(cv_img_frame, uc, cv_img_prevFrame, cv_img_substractFrame,
			pixelSum, pixelSumL, pixelSumR, *leftBlock, *rightBlock);

		if (pixelSum > 1000)
		{
			if (pixelSum > 320*240/3)
			{
				continue;
			}
			if (pixelSumL > 750) isL = true;	else isL = false;
			if (pixelSumR > 750) isR = true;	else isR = false;

			showImages(*cv_img_frameShow, *cv_img_frame, *cv_img_substractFrame,
				cv_draw_blockL, cv_draw_blockR, isL, isR, peopleIn, peopleOut);
		}
		else
		{
			continue;
		}
		
		count(isL, isR, wasL, wasR, peopleIn, peopleOut);
		
	}
	
	cv::waitKey();
	cv_vid_video->release();
	cv::destroyAllWindows();

	delete cv_vid_video;
	delete cv_img_frame;
	delete cv_img_prevFrame;
	delete cv_img_frameShow;
	delete cv_img_substractFrame;
	delete leftBlock;
	delete rightBlock;
}