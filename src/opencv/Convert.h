#pragma once
#include "Opencv.h"

template<typename T>
float scf(T x_in);

template<typename T>
unsigned char scuc(T x_in);


template<typename T>
unsigned short scus(T x_in);

cv::Mat convert_to_Y(cv::Mat& img_in);

cv::Mat convert_to_C3(cv::Mat& img_in);


