                              //SSAlgorithms.h//                                
//////////////////////////////////////////////////////////////////////////////////
//																				//
// Author:  Simeon Kosnitsky													//
//          skosnits@gmail.com													//
//																				//
// License:																		//
//     This software is released into the public domain.  You are free to use	//
//     it in any way you like, except that you may not sell this source code.	//
//																				//
//     This software is provided "as is" with no expressed or implied warranty.	//
//     I accept no liability for any damage or loss of business that this		//
//     software may cause.														//
//																				//
//////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "IPAlgorithms.h"
#include "DataTypes.h"
#include "MyClosedFigure.h"
#include "Video.h"
#include <string>

using namespace std;

extern int		g_RunSubSearch;

extern int		g_DL;	 //sub frame length
extern double	g_tp;	 //text procent
extern double	g_mtpl;  //min text len (in procent)
extern double	g_sse;	 //sub square error
extern double	g_veple; //vedges points line error

extern bool g_fast_search;

void SetVideoWindowSettins(CVideo *pV, double dx_min, double dx_max, double dy_min, double dy_max);

s64 SearchSubtitles(CVideo *pV, s64 Begin, s64 End);
s64 FastSearchSubtitles(CVideo *pV, s64 Begin, s64 End);

int CompareTwoImages(custom_buffer<int> &Im1, custom_buffer<int> &ImNFF1, custom_buffer<int> &Im2, custom_buffer<int> &ImNFF2, int size);

int AnalyseImage(custom_buffer<int> &Im, int w, int h);

int CompareTwoSubs(custom_buffer<int> &Im1, custom_buffer<int> &ImVE1, custom_buffer<int> &Im2, custom_buffer<int> &ImVE2, int w, int h);

int PreCompareTwoSubs(custom_buffer<int> &Im1, custom_buffer<int> &Im2, custom_buffer<int> &ImRES, custom_buffer<int> &lb, custom_buffer<int> &le, int w, int h); // return ln

int FinalCompareTwoSubs1(custom_buffer<int> &ImRES, custom_buffer<int> &lb, custom_buffer<int> &le, int ln, custom_buffer<int> &ImVE1, custom_buffer<int> &ImVE2, int w, int h); // return 0 or 1
int FinalCompareTwoSubs2(custom_buffer<int> &ImRES, custom_buffer<int> &lb, custom_buffer<int> &le, int ln, custom_buffer<int> &ImVE1, custom_buffer<int> &ImVE2, int w, int h);

int DifficultCompareTwoSubs(custom_buffer<int> &ImRGB1, custom_buffer<int> &ImF1, custom_buffer<int> &ImRGB2, custom_buffer<int> &ImF2, int w, int h);

int SimpleCombineTwoImages(custom_buffer<int> &Im1, custom_buffer<int> &Im2, int size);

int GetCombinedSquare(custom_buffer<int> &Im1, custom_buffer<int> &Im2, int size);

void AddTwoImages(custom_buffer<int> &Im1, custom_buffer<int> &Im2, custom_buffer<int> &ImRES, int size);
void AddTwoImages(custom_buffer<int> &Im1, custom_buffer<int> &Im2, int size);

int ConvertImage(custom_buffer<int> &ImRGB, custom_buffer<int> &ImF, custom_buffer<int> &ImVE, int w, int h);

int GetAndConvertImage(custom_buffer<int> &ImRGB, custom_buffer<int> &ImFF, custom_buffer<int> &ImSF, custom_buffer<int> &ImTF, custom_buffer<int> &ImVE, custom_buffer<int> &ImNE, custom_buffer<int> &ImHE, CVideo *pVideo, int w, int h);

void ImToNativeSize(custom_buffer<int> &Im, int w, int h);

string VideoTimeToStr(s64 pos);