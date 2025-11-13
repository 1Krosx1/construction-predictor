/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * predictEnsemble.c
 *
 * Code generation for function 'predictEnsemble'
 *
 */

/* Include files */
#include "predictEnsemble.h"
#include "CompactRegressionEnsemble.h"
#include "rt_nonfinite.h"

/* Function Definitions */
double predictEnsemble(const double X[32])
{
  /*  Predict cost using pre-trained ensemble model. */
  /*  X must be N×65 (N samples, 65 features) */
  /*  Load the trained model */
  /*  Predict */
  return c_CompactRegressionEnsemble_pre(X);
}

/* End of code generation (predictEnsemble.c) */
