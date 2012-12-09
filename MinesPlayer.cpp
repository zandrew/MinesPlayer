#include "stdafx.h"
#include <opencv2\highgui\highgui.hpp>
#include <Windows.h>

/**
* @function main
*/
int main( int argc, const char** argv )
{
	CvCapture* capture;
	IplImage* frame = 0;
	HWND hwnd;
	do{
		//Read the video stream
		capture = cvCaptureFromCAM(0);
		frame = cvQueryFrame( capture );

		// create a window to display detected faces
		cvNamedWindow("Mine's Player", CV_WINDOW_AUTOSIZE);

		// display face detections
		cvShowImage("Mine's Player", frame);

		hwnd = (HWND)cvGetWindowHandle("Mine's Player");
		if( cvWaitKey(1) == 27 ) break;
	}while(IsWindowVisible(hwnd));

	// clean up and release resources
	cvReleaseImage(&frame);

	return 0;
}

