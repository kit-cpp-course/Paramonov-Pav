#include "pch.h"
#include <iostream>
#include "T.ImageLoad.h"
#include "MenuText.h"
#include "5.EdgeTracking.h"
#include <opencv2/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "T_ImgArray.h"
#include "Parasite.h"
using namespace cv;
//using namespace Edge;
int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Russian");
	string Path;
	if (argc >= 2) {
		Path = argv[1];
	}
	else {
		Path = "C:/Users/Public/Pictures/Sample Pictures/Penguins.jpg";
	}
	
	ImageLoad File(Path);

	Mat Img = File.GetMat();



	if (Img.empty()) {
		std::cout << "File not Found in :" << Path;
	}
	else
	{
		EdgeTrack Canny(Img);
		UserCommunication UI;
		bool flag = true;
		while (flag)
		{
			UI.ShowMenu();
			switch (UI.UserResponse()) {
			case(0):
				flag = false;
				break;
			case(1):
				imshow(UI.Choice_1, Canny.GetSmoothedMat());
				imwrite("C:/Users/Public/Pictures/Sample Pictures/Result1.jpg", Canny.GetSmoothedMat());
				break;
			case(2):
				imshow(UI.Choice_2, Canny.GetGradientSearchResult());
				imwrite("C:/Users/Public/Pictures/Sample Pictures/Result2.jpg", Canny.GetGradientSearchResult());
				break;
			case(3):
				imshow(UI.Choice_3, Canny.GetNonMaxSuprResult());
				imwrite("C:/Users/Public/Pictures/Sample Pictures/Result3.jpg", Canny.GetNonMaxSuprResult());
				break;
			case(4):
				imshow(UI.Choice_4, Canny.GetDoubleThresholdResult());
				imwrite("C:/Users/Public/Pictures/Sample Pictures/Result4.jpg", Canny.GetDoubleThresholdResult());
				break;
			case(5):
				imshow(UI.Choice_5, Canny.GetEdgeTrackingResult());
				imwrite("C:/Users/Public/Pictures/Sample Pictures/Result5.jpg", Canny.GetEdgeTrackingResult());
				break;
			case(6):
				imshow(UI.Choice_6, File.GetMat());
				break;
			}
			waitKey(0);
			destroyAllWindows();
			system("CLS");

			
		}
	}
}

