#include "ShowImages.h"
#include <string>

static std::string s_textIn;
static std::string s_textOut;
static std::string s_textInCount;
static std::string s_textOutCount;
void showImages(
	cv::Mat& cv_img_frameShow, cv::Mat& cv_img_frame, cv::Mat& cv_img_substractFrame,
	cv::Rect& cv_draw_blockL, cv::Rect& cv_draw_blockR,
	bool& isL,
	bool& isR,
	unsigned char& peopleIn,
	unsigned char& peopleOut
	)

{
	cv_img_frameShow = cv_img_frame.clone();
	if(isL)
		cv::rectangle(cv_img_frameShow, cv_draw_blockL, { 10,250,10 }, 2);
	else
		cv::rectangle(cv_img_frameShow, cv_draw_blockL, { 10,10,250 }, 2);
	if (isR)
		cv::rectangle(cv_img_frameShow, cv_draw_blockR, { 10,250,10 }, 2);
	else
		cv::rectangle(cv_img_frameShow, cv_draw_blockR, { 10,10,250 }, 2);

	cv::rectangle(cv_img_substractFrame, cv_draw_blockL, 255, 2);
	cv::rectangle(cv_img_substractFrame, cv_draw_blockR, 255, 2);

	

	s_textInCount = std::to_string(peopleIn);
	s_textOutCount = std::to_string(peopleOut);

	s_textIn = "In: ";
	s_textOut = "Out: ";
	
	cv::putText(cv_img_frameShow, //target image
		s_textIn+ s_textInCount, //text
		cv::Point(cv_img_frameShow.cols/10, cv_img_frameShow.rows*100/105), //top-left position
		cv::FONT_HERSHEY_DUPLEX,
		1.0,
		CV_RGB(200, 20, 20), //font color
		2);
	cv::putText(cv_img_frameShow, //target image
		s_textOut + s_textOutCount, //text
		cv::Point(cv_img_frameShow.cols / 2, cv_img_frameShow.rows * 100 / 105), //top-left position
		cv::FONT_HERSHEY_DUPLEX,
		1.0,
		CV_RGB(200, 20, 20), //font color
		2);
	imshow("Frame", cv_img_frameShow);
	imshow("SubstractFrame", cv_img_substractFrame);

	cv::waitKey(1000/60);
}
