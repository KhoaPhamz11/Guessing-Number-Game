#include <climits>
#include <cmath>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PRINT_FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void printLine();

void printIntro();

void printMenu();

void printTutorials();

void printResult(int attempt);

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ARRAY_FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int *generateArr(int size);

void enterArr(int *arr, int n);

void deleteArr(int *arr);

void printArr(int *arr, int size);

int *generate_keyArr(int length);

void keyCheck(int *arr, int *key, int size);

bool isSameArray(int *arr1, int *arr2, int size);

bool hasDuplicate(int *arr, int n);

int *copyArr(int *arr, int size);
