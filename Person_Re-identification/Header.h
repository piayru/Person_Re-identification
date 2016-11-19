#ifndef HEADER_H
#define HEADER_H
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;
class Catch_IPCamera
{
public:
	static void Handel();

private:

};

class Person_IDentification
{
public:
void Handel(Mat Identification_Image);

private:

};

#endif // !HEADER_H