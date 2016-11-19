#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include "Header.h"
using namespace cv;

void Catch_IPCamera::Handel() {
	VideoCapture vcap;
	Mat image;
	Person_IDentification PI;
	const std::string videoStreamAddress = "http://admin:cvlab102d@203.64.91.87:80/video/mjpg.cgi?user=admin&password=cvlab102d&channel=0&.mjpg"; //rtsp://192.168.1.100:554/onvif/live/1
	if (!vcap.open(videoStreamAddress)) {
		std::cout << "Error opening video stream or file" << std::endl;
	}
	for (;;) {
		if (!vcap.read(image)) {
			std::cout << "No frame" << std::endl;
			cv::waitKey();
		}
		cv::imshow("Output Window", image);
		PI.Handel(image);
		if (cv::waitKey(1) >= 0) break;
	}
}

