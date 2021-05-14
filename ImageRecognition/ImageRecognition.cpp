// CvPlayground.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;



/*
Below are the details of the requirements and steps for this project:
1. For ALL training images, do the following pre-processing:
	a. Convert to grayscale images, and adjust the brightness if necessary (e.g. if average
	brightness is less than 0.4, increase brightness; if average brightness is greater than
	0.6, reduce brightness)

	b. Resize the image to TWO different sizes: 200*200 and 50*50 and save them.

2. Extract SIFT features on ALL training images and save the data.

3. Extract Histogram features on ALL training images and save the data.

4. Perform the following FOUR TRAINING on the data:
	a. Represent the image directly using the 50*50 (2500) pixel values and use the
	Nearest Neighbour classifier

	b. Represent the image using SIFT feature data and use Nearest Neighbour classifier

	c. Represent the image using histogram feature data and use Nearest Neighbour
	classifier

	d. Represent the image using SIFT feature data and use linear SVM classifer

5. Test the FOUR trained classifiers using ALL test images and report the following results:
	a. percentage of correctly classified images in the test set
	
	b. percentage of False Positive (images that are falsely classified)
	
	c. percentage of False Negative (images that are not classified)

6. Write UP – please generate a concise report for the project. In the report you will
describe how you implemented the project; and report the results in step 5. Also in the
report, please briefly analyze and discuss the results you get from step 5 (e.g.
comparisons, why one method performs better than the other) and any other findings
(e.g. what affected the accuracy).
*/

//open all images
vector<Mat> openImages()
{
	//vector of names of folders
	vector<cv::String> folders;
	folders.push_back("bedroom");
	folders.push_back("Coast");
	folders.push_back("Forest");
	folders.push_back("Highway");

	//vector of names of files
	vector<cv::String> fn;
	glob("ProjData/Train/*.jpg", fn, true);
	
	vector<Mat> images;

	size_t count = fn.size(); //number of png files in images folder
	for (size_t i = 0; i < count; i++)
	{
		//push images to vector
		images.push_back(imread(fn[i], IMREAD_GRAYSCALE, beta = ));

	}

	return images;

}


vector<Mat> preprocess(vector<Mat> images)
{
	//a. Convert to grayscale images, and adjust the brightness if necessary (e.g. if average
	//brightness is less than 0.4, increase brightness; if average brightness is greater than
	//	0.6, reduce brightness)
	for (int i = 0; i < images.size(); i++)
	{
		cout << mean(images[i]) / 256  << endl;
		images[i].convertTo(images[i], IMREAD_GRAYSCALE, )

		//resize(allImages[i], allImages[i], cv::Size(100, 100));
	}

	//b.Resize the image to TWO different sizes : 200 * 200 and 50 * 50 and save them.
	
	return images;
}


int main()
{ //test2

	vector<Mat> images;
	images = openImages();
	
	vector<Mat> preprocessed;
	preprocessed = preprocess(images);

	Mat image = Mat::zeros(300, 600, CV_8UC3);
	circle(image, Point(250, 150), 100, Scalar(0, 255, 128), -100);
	circle(image, Point(350, 150), 100, Scalar(255, 255, 255), -100);
	imshow("Display Window", image);
	waitKey(0);
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
