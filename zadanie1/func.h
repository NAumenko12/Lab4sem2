#pragma once
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

double f(double x);
double df(double x);
double ddf(double x);
double phiPositive(double x);
double phiNegative(double x);

vector<double> solveRoot(const string& title, double a, double b, double x0, bool isPositive, double epsilon);
double bisectionMethod(double a, double b, double epsilon);
double newtonMethod(double x0, double epsilon);
double simpleIterationMethod(double x0, double epsilon, bool isPositive);

void printMethodHeader(const string& methodName, double a, double b);
void printMethodHeader(const string& methodName, double x0);
void printMethodRow(int n, double a, double b);
void printMethodRow(int n, double x, double nextX, double diff);
void printRootResult(double root, int n);
