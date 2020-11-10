
#include <Windows.h>
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <random>

//다이렉트x 관련 헤더
#include <d2d1.h>
#include <d2d1helper.h>

//COM
#include <wincodec.h>

#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "WindowsCodecs.lib")
//stdafx.h
#pragma comment(lib, "Winmm.lib")//이거


#define SAFE_RELEASE(p) { if(p){p->Release();} p=NULL; }
#define SAFE_DELETE(p) {if(p!=nullptr){delete(p);} p=nullptr; }
#define PI 3.141592653589793f

typedef D2D1_POINT_2F Point;