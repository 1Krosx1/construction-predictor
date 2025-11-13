/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * predictOneWithCache.h
 *
 * Code generation for function 'predictOneWithCache'
 *
 */

#ifndef PREDICTONEWITHCACHE_H
#define PREDICTONEWITHCACHE_H

/* Include files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
double b_predictOneWithCache(const double X[32], double *cachedScore,
                             double *cachedWeights,
                             const double weak_learner_CutPredictorIndex[17],
                             const double weak_learner_Children[34],
                             const double weak_learner_CutPoint[17],
                             const boolean_T weak_learner_NanCutPoints[17],
                             const double weak_learner_NodeMean[17],
                             boolean_T *cached);

double predictOneWithCache(const double X[32],
                           const double weak_learner_CutPredictorIndex[17],
                           const double weak_learner_Children[34],
                           const double weak_learner_CutPoint[17],
                           const boolean_T weak_learner_NanCutPoints[17],
                           const double weak_learner_NodeMean[17],
                           double *cachedScore, double *cachedWeights);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (predictOneWithCache.h) */
