#include "opencv2/imgproc/imgproc.hpp"  
#include "opencv2/objdetect/objdetect.hpp"  
#include "opencv2/highgui/highgui.hpp" 
#include <stdio.h>  
#include <string.h>  
#include <ctype.h>  
#include "Header.h"

using namespace cv;
using namespace std;

void Person_IDentification::Handel(Mat Identification_Image)
{
	FILE* f = 0;
	char _filename[1024];

	HOGDescriptor hog;
	hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());
	namedWindow("people detector", 1);


		fflush(stdout);
		vector<Rect> found, found_filtered;
		double t = (double)getTickCount();	
		hog.detectMultiScale(Identification_Image, found, 0, Size(8, 8), Size(32, 32), 1.05, 2);
		t = (double)getTickCount() - t;
		printf("tdetection time = %gms\n", t*1000. / cv::getTickFrequency());
		size_t i, j;
		for (i = 0; i < found.size(); i++)
		{
			Rect r = found[i];
			for (j = 0; j < found.size(); j++)
				if (j != i && (r & found[j]) == r)
					break;
			if (j == found.size())
				found_filtered.push_back(r);
		}
		for (i = 0; i < found_filtered.size(); i++)
		{
			Rect r = found_filtered[i];
			r.x += cvRound(r.width*0.1);
			r.width = cvRound(r.width*0.8);
			r.y += cvRound(r.height*0.07);
			r.height = cvRound(r.height*0.8);
			rectangle(Identification_Image, r.tl(), r.br(), cv::Scalar(0, 255, 0), 3);
		}
		imshow("people detector", Identification_Image);
		/*int c = waitKey(5000) & 255;

		waitKey();
		return 0;*/
}