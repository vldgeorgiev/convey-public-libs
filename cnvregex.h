/*
  The MIT License (MIT)

  Copyright (c) 2015 Convey Compliance Systems, Inc.

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/

#ifndef cnvregex_h
#define cnvregex_h

#include <Windows.h>

#ifdef _DEBUGREGEX
  #ifdef _WIN64
    #ifdef USE_UNICODE_DLL
      #define CNVREGEX_DLL "cnvregex_ud64_1-0-0.dll"
    #else
      #define CNVREGEX_DLL "cnvregex_d64_1-0-0.dll"
    #endif
  #else
    #ifdef USE_UNICODE_DLL
      #define CNVREGEX_DLL "cnvregex_ud32_1-0-0.dll"
    #else
      #ifdef IDE_DEBUG
        #define CNVREGEX_DLL "cnvregex.dll"
      #else
        #define CNVREGEX_DLL "cnvregex_d32_1-0-0.dll"
      #endif
    #endif
  #endif
#else
  #ifdef _WIN64
    #ifdef USE_UNICODE_DLL
      #define CNVREGEX_DLL "cnvregex_ur64_1-0-0.dll"
    #else
      #define CNVREGEX_DLL "cnvregex_r64_1-0-0.dll"
    #endif
  #else
    #ifdef USE_UNICODE_DLL
      #define CNVREGEX_DLL "cnvregex_ur32_1-0-0.dll"
    #else
      #define CNVREGEX_DLL "cnvregex_r32_1-0-0.dll"
    #endif
  #endif
#endif

void InitCnvRegEx();
void DoneCnvRegEx();

char* RegExpr_Create(void ** _this);
char* RegExpr_Free(void* _this);
char* RegExpr_SetInputString(void* _this, char* AInputString);
char* RegExpr_SetExpression(void* _this, char* AExpression);
wchar_t* RegExpr_SetInputStringW(void* _this, wchar_t* AInputString);
wchar_t* RegExpr_SetExpressionW(void* _this, wchar_t* AExpression);
char* RegExpr_Exec(void* _this, BOOL* AMatch);
char* RegExpr_ExecNext(void* _this, BOOL* AMore);

typedef void* (__cdecl *GetMem_t)(size_t Size);
typedef int (__cdecl *FreeMem_t)(void* P);
typedef void* (__cdecl *ReallocMem_t)(void* P, size_t Size);

void OverrideMemAllocator(GetMem_t pGetMem, ReallocMem_t pReallocMem, FreeMem_t pFreeMem);
void ResetMemAllocator();


#endif