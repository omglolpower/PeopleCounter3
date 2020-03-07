#include "Convert.h"


template<typename T>
float scf(T x_in)
{
	return static_cast<float>(x_in);
}

template<typename T>
unsigned char scuc(T x_in)
{
	return static_cast<unsigned char>(x_in);
}

template<typename T>
unsigned short scus(T x_in)
{
	return static_cast<unsigned short>(x_in);
}

cv::Mat convert_to_Y(cv::Mat& img_in)
{
	unsigned short Y = 0;
	cv::Mat r = ZEROS(img_in);
	UIFORIXY(x, y, img_in)
	{
		Y = 36 * scus(img_in.at<cv::Vec3b>(y, x)[2]) +
			53 * scus(img_in.at<cv::Vec3b>(y, x)[1]) +
			11 * scus(img_in.at<cv::Vec3b>(y, x)[0]);
		Y /= 100;

		r.at<uchar>(y, x) =scuc(Y);
	}
	
	return r;
}

cv::Mat convert_to_C3(cv::Mat& img_in)
{
	unsigned short Y = 0;
	cv::Mat r = ZEROS3(img_in);
	UIFORIXY(x, y, img_in)
	{
		Y = scus(img_in.at<uchar>(y, x));
		r.at<cv::Vec3b>(y, x)[2] = scuc(Y * 36 / 100);
		r.at<cv::Vec3b>(y, x)[1] = scuc(Y * 53 / 100);
		r.at<cv::Vec3b>(y, x)[0] = scuc(Y * 11 / 100);
	}

	return r;
}