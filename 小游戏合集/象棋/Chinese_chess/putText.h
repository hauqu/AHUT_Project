#pragma once
#ifndef PUTTEXT_H_
#define PUTTEXT_H_

#include <windows.h>
#include <string>
#include <opencv2/opencv.hpp>

using namespace cv;

void GetStringSize(HDC hDC, const char* str, int* w, int* h);
void putTextZH(Mat& dst, const char* str, Point org, Scalar color, int fontSize,
	const char* fn = "Arial", bool italic = false, bool underline = false);

#endif // PUTTEXT_H_

/*

#include "opencv2/opencv.hpp"

#include "putText.h"

using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("src.jpg");

	putTextZH(img, "Arial���廻...\n����ʾ!", Point(50, 50), Scalar(0, 0, 255), 30, "Arial");
	putTextZH(img, "΢���ź����廻...\n�У�б�壬�»��ߣ���ʾ!", Point(50, 100), Scalar(0, 255, 0), 30, "΢���ź�", true, true);
	putTextZH(img, "�������廻...\n�У�б�壬�»��ߣ���ʾ!", Point(50, 200), Scalar(128, 255, 0), 30, "����", true, true);

	imshow("test", img);

	waitKey();

	return 0;
}



*/