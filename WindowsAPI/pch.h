#pragma once

#include <windows.h>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include "Types.h"
#include "Defines.h"
//#include "Utils.h"
using namespace std;

#include <format>

#define _CRTDEBUG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

#include "Utils.h"