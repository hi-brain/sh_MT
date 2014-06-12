//
// MATLAB コンパイラー:5.1 (R2014a)
// 日付:Mon Jun 09 10:33:37 2014
// 引数: "-B" "macro_default" "-B" "cpplib:shMT" "-W" "cpplib:shMT" "-T"
// "link:lib" "-d" "shMT" "shPars.m" "shModelMtLinear.m"
// "shModelMtPreThresholdBlur.m" "shModelHalfWaveRectification.m"
// "shModelMtPostThresholdBlur.m" "shModelMtNormalization.m" "-a"
// "defaultParameters.mat" 
//

#ifndef __shMT_h
#define __shMT_h 1

#if defined(__cplusplus) && !defined(mclmcrrt_h) && defined(__linux__)
#  pragma implementation "mclmcrrt.h"
#endif
#include "mclmcrrt.h"
#include "mclcppclass.h"
#ifdef __cplusplus
extern "C" {
#endif

#if defined(__SUNPRO_CC)
/* Solaris shared libraries use __global, rather than mapfiles
 * to define the API exported from a shared library. __global is
 * only necessary when building the library -- files including
 * this header file to use the library do not need the __global
 * declaration; hence the EXPORTING_<library> logic.
 */

#ifdef EXPORTING_shMT
#define PUBLIC_shMT_C_API __global
#else
#define PUBLIC_shMT_C_API /* No import statement needed. */
#endif

#define LIB_shMT_C_API PUBLIC_shMT_C_API

#elif defined(_HPUX_SOURCE)

#ifdef EXPORTING_shMT
#define PUBLIC_shMT_C_API __declspec(dllexport)
#else
#define PUBLIC_shMT_C_API __declspec(dllimport)
#endif

#define LIB_shMT_C_API PUBLIC_shMT_C_API


#else

#define LIB_shMT_C_API

#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_shMT_C_API 
#define LIB_shMT_C_API /* No special import/export declaration */
#endif

extern LIB_shMT_C_API 
bool MW_CALL_CONV shMTInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_shMT_C_API 
bool MW_CALL_CONV shMTInitialize(void);

extern LIB_shMT_C_API 
void MW_CALL_CONV shMTTerminate(void);



extern LIB_shMT_C_API 
void MW_CALL_CONV shMTPrintStackTrace(void);

extern LIB_shMT_C_API 
bool MW_CALL_CONV mlxShPars(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_shMT_C_API 
bool MW_CALL_CONV mlxShModelMtLinear(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                     *prhs[]);

extern LIB_shMT_C_API 
bool MW_CALL_CONV mlxShModelMtPreThresholdBlur(int nlhs, mxArray *plhs[], int nrhs, 
                                               mxArray *prhs[]);

extern LIB_shMT_C_API 
bool MW_CALL_CONV mlxShModelHalfWaveRectification(int nlhs, mxArray *plhs[], int nrhs, 
                                                  mxArray *prhs[]);

extern LIB_shMT_C_API 
bool MW_CALL_CONV mlxShModelMtPostThresholdBlur(int nlhs, mxArray *plhs[], int nrhs, 
                                                mxArray *prhs[]);

extern LIB_shMT_C_API 
bool MW_CALL_CONV mlxShModelMtNormalization(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                            *prhs[]);


#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__BORLANDC__)

#ifdef EXPORTING_shMT
#define PUBLIC_shMT_CPP_API __declspec(dllexport)
#else
#define PUBLIC_shMT_CPP_API __declspec(dllimport)
#endif

#define LIB_shMT_CPP_API PUBLIC_shMT_CPP_API

#else

#if !defined(LIB_shMT_CPP_API)
#if defined(LIB_shMT_C_API)
#define LIB_shMT_CPP_API LIB_shMT_C_API
#else
#define LIB_shMT_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_shMT_CPP_API void MW_CALL_CONV shPars(int nargout, mwArray& pars);

extern LIB_shMT_CPP_API void MW_CALL_CONV shModelMtLinear(int nargout, mwArray& varargout, const mwArray& varargin);

extern LIB_shMT_CPP_API void MW_CALL_CONV shModelMtLinear(int nargout, mwArray& varargout);

extern LIB_shMT_CPP_API void MW_CALL_CONV shModelMtLinear(const mwArray& varargin);

extern LIB_shMT_CPP_API void MW_CALL_CONV shModelMtLinear();

extern LIB_shMT_CPP_API void MW_CALL_CONV shModelMtPreThresholdBlur(int nargout, mwArray& varargout, const mwArray& varargin);

extern LIB_shMT_CPP_API void MW_CALL_CONV shModelMtPreThresholdBlur(int nargout, mwArray& varargout);

extern LIB_shMT_CPP_API void MW_CALL_CONV shModelMtPreThresholdBlur(const mwArray& varargin);

extern LIB_shMT_CPP_API void MW_CALL_CONV shModelMtPreThresholdBlur();

extern LIB_shMT_CPP_API void MW_CALL_CONV shModelHalfWaveRectification(int nargout, mwArray& varargout, const mwArray& varargin);

extern LIB_shMT_CPP_API void MW_CALL_CONV shModelHalfWaveRectification(int nargout, mwArray& varargout);

extern LIB_shMT_CPP_API void MW_CALL_CONV shModelHalfWaveRectification(const mwArray& varargin);

extern LIB_shMT_CPP_API void MW_CALL_CONV shModelHalfWaveRectification();

extern LIB_shMT_CPP_API void MW_CALL_CONV shModelMtPostThresholdBlur(int nargout, mwArray& varargout, const mwArray& varargin);

extern LIB_shMT_CPP_API void MW_CALL_CONV shModelMtPostThresholdBlur(int nargout, mwArray& varargout);

extern LIB_shMT_CPP_API void MW_CALL_CONV shModelMtPostThresholdBlur(const mwArray& varargin);

extern LIB_shMT_CPP_API void MW_CALL_CONV shModelMtPostThresholdBlur();

extern LIB_shMT_CPP_API void MW_CALL_CONV shModelMtNormalization(int nargout, mwArray& varargout, const mwArray& varargin);

extern LIB_shMT_CPP_API void MW_CALL_CONV shModelMtNormalization(int nargout, mwArray& varargout);

extern LIB_shMT_CPP_API void MW_CALL_CONV shModelMtNormalization(const mwArray& varargin);

extern LIB_shMT_CPP_API void MW_CALL_CONV shModelMtNormalization();

#endif
#endif
