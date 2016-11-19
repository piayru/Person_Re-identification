#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>

using namespace cv;

int main() {
	VideoCapture vcap;
	Mat image;

	const std::string videoStreamAddress = "http://admin:cvlab102d@203.64.91.87:80/video/mjpg.cgi?user=admin&password=cvlab102d&channel=0&.mjpg"; //rtsp://192.168.1.100:554/onvif/live/1
	if (!vcap.open(videoStreamAddress)) {
		std::cout << "Error opening video stream or file" << std::endl;
		return -1;
	}

	for (;;) {
		if (!vcap.read(image)) {
			std::cout << "No frame" << std::endl;
			cv::waitKey();
		}
		cv::imshow("Output Window", image);
		if (cv::waitKey(1) >= 0) break;
	}
	return 0;
}