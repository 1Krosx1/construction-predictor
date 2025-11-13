/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * predictOneWithCache.c
 *
 * Code generation for function 'predictOneWithCache'
 *
 */

/* Include files */
#include "predictOneWithCache.h"
#include "CompactRegressionTree.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"

/* Function Definitions */
double b_predictOneWithCache(const double X[32], double *cachedScore,
                             double *cachedWeights,
                             const double weak_learner_CutPredictorIndex[17],
                             const double weak_learner_Children[34],
                             const double weak_learner_CutPoint[17],
                             const boolean_T weak_learner_NanCutPoints[17],
                             const double weak_learner_NodeMean[17],
                             boolean_T *cached)
{
  double score;
  if (rtIsNaN(*cachedScore)) {
    *cachedScore = 0.0;
  }
  score =
      *cachedScore + CompactRegressionTree_predict(
                         weak_learner_CutPredictorIndex, weak_learner_Children,
                         weak_learner_CutPoint, weak_learner_NanCutPoints,
                         weak_learner_NodeMean, X) *
                         0.015648867132149993;
  *cachedWeights += 0.015648867132149993;
  *cachedScore = score;
  *cached = true;
  return score;
}

double predictOneWithCache(const double X[32],
                           const double weak_learner_CutPredictorIndex[17],
                           const double weak_learner_Children[34],
                           const double weak_learner_CutPoint[17],
                           const boolean_T weak_learner_NanCutPoints[17],
                           const double weak_learner_NodeMean[17],
                           double *cachedScore, double *cachedWeights)
{
  double score;
  score = CompactRegressionTree_predict(
              weak_learner_CutPredictorIndex, weak_learner_Children,
              weak_learner_CutPoint, weak_learner_NanCutPoints,
              weak_learner_NodeMean, X) *
          0.015648867132149993;
  *cachedScore = score;
  *cachedWeights = 0.015648867132149993;
  return score;
}

/* End of code generation (predictOneWithCache.c) */
