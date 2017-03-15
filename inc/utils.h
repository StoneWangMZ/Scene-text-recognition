#ifndef __MYLIB__
#define __MYLIB__

//#define WEBCAM_MODE

#define THRESHOLD_STEP 2
#define MIN_ER_AREA 100
#define MAX_ER_AREA 90000
#define NMS_STABILITY_T 2
#define NMS_OVERLAP_COEF 0.7

#define MAX_WIDTH 1500
#define MAX_HEIGHT 800

#include <iostream>
#include <chrono>
#include <opencv.hpp>

#include "ER.h"
#include "OCR.h"
#include "adaboost.h"


using namespace std;
using namespace cv;


// Testing Functions
bool load_test_file(Mat &src, int n);
void show_result(Mat &src, vector<ERs> &all, vector<ERs> &pool, vector<ERs> &strong, vector<ERs> &weak, ERs &tracked, vector<Text> &text);
void draw_linear_time_MSER(string img_name);
void draw_multiple_channel(string img_name);
void test_MSER_time(string img_name);
vector<Vec4i> load_gt(int n);
Vec6d calc_detection_rate(int n, vector<Text> &text);
void save_deteval_xml(vector<vector<Text>> &text);

// Training Functions
void get_canny_data();
void rotate_image();
void bootstrap();
void get_ocr_data(int argc, char **argv, int type);
void train_classifier();
void train_cascade();
void opencv_train();

// Other
void draw_all_er();
#endif