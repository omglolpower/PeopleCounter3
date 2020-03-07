#include "Substract.h"


void cv_Substract(cv::Mat* cv_img_frame, unsigned char &uc, cv::Mat* cv_img_prevFrame, cv::Mat* cv_img_substractFrame,
	unsigned int& pixelSum, unsigned int& pixelSumL, unsigned int& pixelSumR, sBlock& leftBlock, sBlock& rightBlock)
{
	UIFORXY(x, y, (*cv_img_frame))
	{
		uc = myAbs(
			cv_img_frame->at<cv::Vec3b>(y, x)[1] - cv_img_prevFrame->at<cv::Vec3b>(y, x)[1]
		);
		if (uc > 20)
		{
			cv_img_substractFrame->at<uchar>(y, x) = 255;
			++pixelSum;
			if (
				x > leftBlock.m_x &&
				x < leftBlock.m_x + leftBlock.m_a)
			{
				++pixelSumL;
			}
			else if (
				x > rightBlock.m_x &&
				x < rightBlock.m_x + rightBlock.m_a
				)
			{
				++pixelSumR;
			}
		}
	}
}
