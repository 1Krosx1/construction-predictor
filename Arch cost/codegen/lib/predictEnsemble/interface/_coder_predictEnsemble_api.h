/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * _coder_predictEnsemble_api.h
 *
 * Code generation for function 'predictEnsemble'
 *
 */

#ifndef _CODER_PREDICTENSEMBLE_API_H
#define _CODER_PREDICTENSEMBLE_API_H

/* Include files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#include <string.h>

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
real_T predictEnsemble(real_T X[32]);

void predictEnsemble_api(const mxArray *prhs, const mxArray **plhs);

void predictEnsemble_atexit(void);

void predictEnsemble_initialize(void);

void predictEnsemble_terminate(void);

void predictEnsemble_xil_shutdown(void);

void predictEnsemble_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_predictEnsemble_api.h) */
