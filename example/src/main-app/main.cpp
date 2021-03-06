/*
This is a demo application to showcase the UI components of cvui.

Copyright (c) 2016 Fernando Bevilacqua <dovyski@gmail.com>
Licensed under the MIT license.
*/

#include <iostream>

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc.hpp"

#include "cvui.h"

#define WINDOW_NAME		"CVUI Test"

int main(int argc, const char *argv[])
{
	cv::Mat frame = cv::Mat(250, 600, CV_8UC3);
	bool checked = false;
	bool checked2 = true;
	int count = 0;

	// Init a OpenCV window and tell cvui to use it.
	// If cv::namedWindow() is not used, mouse events will
	// not be captured by cvui.
	cv::namedWindow(WINDOW_NAME);
	cvui::init(WINDOW_NAME);

	while (true) {
		// Fill the frame with a nice color
		frame = cv::Scalar(49, 52, 49);

		// Check if ESC key was pressed
		if (cv::waitKey(10) == 27) {
			break;
		}

		// Show some pieces of text. You can also specify the size of the
		// text and its color (using hex 0xRRGGBB CSS-like style).
		cvui::text(frame, 50, 30, "Hey there!");
		cvui::text(frame, 200, 30, "Use hex 0xRRGGBB colors easily", 0.4, 0xff0000);

		// Buttons will return true if they were clicked, which makes
		// handling clicks a breeze.
		if (cvui::button(frame, 50, 50, "Button")) {
			std::cout << "Button clicked!" << std::endl;
		}

		// If you do not specify the button width/height, the size will be
		// automatically adjusted to properly house the label.
		cvui::button(frame, 200, 50, "Button with large label");
		// You can tell the width and height you want
		cvui::button(frame, 410, 50, 15, 15, "x");

		// Window components are useful to create HUDs and similars. At the
		// moment, there is no implementation to constraint content within a
		// a window.
		cvui::window(frame, 50, 100, 120, 100, "Window");
		
		// The counter component can be used to alter int variables. Use
		// the 4th parameter of the function to point it to the variable
		// to be changed.
		cvui::counter(frame, 200, 100, &count);
		
		// Checkboxes also accept a pointer to a variable that controls
		// the state of the checkbox (checked or not). cvui::checkbox() will
		// automatically update the value of the boolean after all
		// interactions, but you can also change it by yourself. Just
		// do "checked = true" somewhere and the checkbox will change
		// its appearance.
		cvui::checkbox(frame, 200, 150, "Checkbox", &checked);
		cvui::checkbox(frame, 200, 180, "A checked checkbox", &checked2);

		// This function must be called *AFTER* all UI components. It does
		// all the behind the scenes magic to handle mouse clicks, etc.
		cvui::update();

		// Show everything on the screen
		cv::imshow(WINDOW_NAME, frame);
	}

	return 0;
}