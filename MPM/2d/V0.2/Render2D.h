#pragma once
#include"ParticleCloud.h"
#include"Parameters.h"
#include<opencv2/opencv.hpp>
#include"File.h"
#include"SDF.h"
#include<time.h>
#include"Scene.h"

#define MAX_ITERATION 64
#define MAX_DISTANCE  800.0f
#define EPSILON 0.001f
#define N 156.0f
#define M_PI 3.14159265358979
#define MAX_DEPTH 3
#define BIAS 0.01f
#define BLACK {0.0f,0.0f,0.0f}
typedef struct { double r, g, b; } Color;
typedef struct {
	double d, reflectivity, eta;
	Color emissive, absorption;
} Result;
Color ColorAdd(Color a, Color b);
Color ColorMultiply(Color a, Color b);
Color ColorScale(Color a, double s);
void Reflect(double ix, double iy, double nx, double ny, double *rx, double *ry);//ʸ������
int Refract(double ix, double iy, double nx, double ny, double eta, double *rx, double *ry);
Color BeerLambert(Color a, double d);
Result UnionOp(Result a, Result b);//��
Result IntersectOp(Result a, Result b);//��
Result SubtractOp(Result a, Result b);//��


class Render2D
{
public:
	Render2D(int h, int w);
	~Render2D();
	cv::Mat canvas;
	int width, height;
	SDF *sdf;
	File* file;
	void CanvasClear();
	void CanvasOutput(int num);
	void CanvasShow();
	void CanvasDraw(vector<Vector2d> pointlist);
	void CanvasDraw(Scene* sc);
	Result SceneDistance(double x, double y);
	Color Trace(double x, double y, double ix, double iy, int depth);
	void PixelCalculate(int value);

};

