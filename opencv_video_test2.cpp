// opencv_video_test2.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"



#include<iostream>
#include<cv.h>
#include<cvaux.h>
#include<cxcore.h>
#include<highgui.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[]){
	cvNamedWindow("test",CV_WINDOW_AUTOSIZE);
	CvCapture *capture = cvCreateFileCapture("C:\test.avi");
	int fps = ( int )cvGetCaptureProperty( capture, CV_CAP_PROP_FPS );
	IplImage *frame;
	//frame = cvLoadImage("E:/My Pictures/2.jpg",1);
	
	while(1){
		frame = cvQueryFrame( capture );
		if( !frame ) {
			cout<<"not have frame"<<endl;
			system("pause");
			break;}
		cvShowImage("test",frame);
		char key=cvWaitKey(1000/fps);
		if ( key==27 ) break;
	}
		
	
	
	
	
	
	cvDestroyWindow("test");
	cvReleaseCapture( &capture );
	cvReleaseImage(&frame);
	return 0;
}