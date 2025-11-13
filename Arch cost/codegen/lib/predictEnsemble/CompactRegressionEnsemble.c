/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * CompactRegressionEnsemble.c
 *
 * Code generation for function 'CompactRegressionEnsemble'
 *
 */

/* Include files */
#include "CompactRegressionEnsemble.h"
#include "CompactRegressionTree.h"
#include "predictEnsemble_internal_types.h"
#include "predictOneWithCache.h"
#include "rt_nonfinite.h"

/* Function Definitions */
double c_CompactRegressionEnsemble_pre(const double Xin[32])
{
  double t0_Children[34];
  double t0_CutPoint[17];
  double t0_CutPredictorIndex[17];
  double t0_NodeMean[17];
  double Yfit;
  double cachedWeights;
  boolean_T b_expl_temp[17];
  boolean_T c_expl_temp[17];
  boolean_T d_expl_temp[17];
  boolean_T expl_temp[17];
  boolean_T t0_NanCutPoints[17];
  boolean_T b;
  c_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  predictOneWithCache(Xin, t0_CutPredictorIndex, t0_Children, t0_CutPoint,
                      t0_NanCutPoints, t0_NodeMean, &Yfit, &cachedWeights);
  d_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  cachedWeights = 0.015648867132149993;
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  e_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  f_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  g_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  h_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  i_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  j_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  k_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  l_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  m_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  n_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  o_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  p_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  q_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  r_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  s_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  t_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  u_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  v_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  w_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  x_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  y_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ab_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  bb_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  cb_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  db_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  eb_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  fb_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  gb_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  hb_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ib_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  jb_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  kb_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  lb_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  mb_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  nb_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ob_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  pb_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  qb_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  rb_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  sb_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  tb_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ub_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  vb_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  wb_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  xb_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  yb_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ac_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  bc_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  cc_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  dc_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ec_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  fc_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  gc_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  hc_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ic_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  jc_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  kc_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  lc_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  mc_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  nc_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  oc_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  pc_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  qc_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  rc_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  sc_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  tc_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  uc_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  vc_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  wc_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  xc_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  yc_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ad_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  bd_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  cd_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  dd_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ed_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  fd_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  gd_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  hd_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  id_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  jd_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  kd_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ld_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  md_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  nd_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  od_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  pd_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  qd_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  rd_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  sd_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  td_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ud_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  vd_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  wd_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  xd_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  yd_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ae_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  be_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ce_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  de_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ee_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  fe_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ge_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  he_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ie_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  je_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ke_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  le_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  me_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ne_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  oe_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  pe_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  qe_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  re_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  se_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  te_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ue_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ve_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  we_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  xe_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ye_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  af_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  bf_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  cf_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  df_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ef_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ff_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  gf_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  hf_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  if_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  jf_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  kf_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  lf_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  mf_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  nf_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  of_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  pf_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  qf_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  rf_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  sf_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  tf_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  uf_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  vf_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  wf_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  xf_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  yf_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ag_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  bg_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  cg_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  dg_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  eg_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  fg_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  gg_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  hg_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ig_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  jg_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  kg_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  lg_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  mg_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ng_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  og_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  pg_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  qg_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  rg_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  sg_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  tg_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ug_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  vg_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  wg_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  xg_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  yg_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ah_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  bh_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ch_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  dh_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  eh_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  fh_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  gh_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  hh_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ih_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  jh_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  kh_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  lh_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  mh_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  nh_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  oh_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ph_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  qh_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  rh_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  sh_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  th_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  uh_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  vh_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  wh_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  xh_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  yh_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ai_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  bi_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ci_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  di_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ei_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  fi_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  gi_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  hi_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ii_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ji_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ki_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  li_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  mi_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ni_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  oi_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  pi_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  qi_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ri_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  si_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ti_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ui_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  vi_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  wi_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  xi_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  yi_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  aj_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  bj_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  cj_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  dj_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ej_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  fj_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  gj_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  hj_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ij_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  jj_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  kj_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  lj_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  mj_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  nj_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  oj_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  pj_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  qj_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  rj_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  sj_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  tj_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  uj_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  vj_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  wj_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  xj_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  yj_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ak_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  bk_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ck_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  dk_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ek_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  fk_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  gk_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  hk_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ik_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  jk_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  kk_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  lk_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  mk_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  nk_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ok_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  pk_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  qk_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  rk_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  sk_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  tk_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  uk_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  vk_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  wk_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  xk_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  yk_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  al_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  bl_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  cl_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  dl_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  el_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  fl_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  gl_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  hl_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  il_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  jl_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  kl_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ll_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ml_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  nl_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ol_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  pl_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ql_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  rl_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  sl_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  tl_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ul_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  vl_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  wl_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  xl_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  yl_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  am_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  bm_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  cm_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  dm_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  em_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  fm_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  gm_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  hm_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  im_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  jm_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  km_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  lm_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  mm_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  nm_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  om_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  pm_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  qm_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  rm_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  sm_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  tm_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  um_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  vm_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  wm_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  xm_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ym_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  an_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  bn_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  cn_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  dn_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  en_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  fn_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  gn_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  hn_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  in_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  jn_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  kn_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ln_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  mn_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  nn_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  on_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  pn_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  qn_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  rn_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  sn_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  tn_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  un_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  vn_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  wn_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  xn_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  yn_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ao_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  bo_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  co_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  do_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  eo_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  fo_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  go_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ho_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  io_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  jo_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ko_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  lo_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  mo_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  no_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  oo_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  po_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  qo_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ro_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  so_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  to_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  uo_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  vo_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  wo_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  xo_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  yo_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ap_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  bp_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  cp_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  dp_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ep_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  fp_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  gp_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  hp_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ip_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  jp_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  kp_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  lp_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  mp_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  np_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  op_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  pp_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  qp_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  rp_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  sp_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  tp_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  up_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  vp_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  wp_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  xp_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  yp_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  aq_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  bq_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  cq_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  dq_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  eq_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  fq_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  gq_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  hq_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  iq_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  jq_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  kq_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  lq_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  mq_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  nq_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  oq_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  pq_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  qq_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  rq_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  sq_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  tq_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  uq_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  vq_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  wq_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  xq_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  yq_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ar_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  br_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  cr_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  dr_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  er_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  fr_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  gr_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  hr_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ir_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  jr_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  kr_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  lr_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  mr_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  nr_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  or_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  pr_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  qr_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  rr_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  sr_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  tr_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ur_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  vr_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  wr_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  xr_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  yr_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  as_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  bs_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  cs_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ds_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  es_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  fs_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  gs_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  hs_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  is_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  js_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ks_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ls_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ms_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ns_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  os_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ps_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  qs_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  rs_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ss_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ts_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  us_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  vs_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ws_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  xs_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ys_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  at_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  bt_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ct_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  dt_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  et_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ft_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  gt_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ht_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  it_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  jt_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  kt_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  lt_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  mt_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  nt_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ot_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  pt_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  qt_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  rt_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  st_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  tt_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ut_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  vt_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  wt_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  xt_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  yt_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  au_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  bu_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  cu_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  du_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  eu_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  fu_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  gu_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  hu_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  iu_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ju_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ku_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  lu_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  mu_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  nu_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ou_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  pu_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  qu_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ru_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  su_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  tu_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  uu_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  vu_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  wu_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  xu_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  yu_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  av_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  bv_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  cv_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  dv_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ev_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  fv_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  gv_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  hv_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  iv_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  jv_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  kv_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  lv_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  mv_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  nv_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ov_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  pv_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  qv_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  rv_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  sv_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  tv_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  uv_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  vv_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  wv_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  xv_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  yv_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  aw_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  bw_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  cw_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  dw_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ew_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  fw_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  gw_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  hw_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  iw_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  jw_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  kw_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  lw_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  mw_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  nw_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ow_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  pw_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  qw_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  rw_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  sw_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  tw_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  uw_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  vw_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ww_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  xw_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  yw_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ax_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  bx_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  cx_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  dx_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ex_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  fx_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  gx_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  hx_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ix_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  jx_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  kx_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  lx_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  mx_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  nx_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ox_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  px_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  qx_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  rx_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  sx_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  tx_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ux_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  vx_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  wx_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  xx_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  yx_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ay_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  by_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  cy_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  dy_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ey_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  fy_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  gy_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  hy_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  iy_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  jy_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ky_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ly_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  my_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ny_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  oy_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  py_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  qy_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ry_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  sy_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ty_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  uy_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  vy_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  wy_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  xy_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  yy_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  aab_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  bab_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  cab_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  dab_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  eab_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  fab_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  gab_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  hab_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  iab_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  jab_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  kab_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  lab_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  mab_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  nab_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  oab_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  pab_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  qab_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  rab_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  sab_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  tab_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  uab_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  vab_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  wab_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  xab_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  yab_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  abb_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  bbb_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  cbb_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  dbb_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ebb_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  fbb_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  gbb_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  hbb_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ibb_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  jbb_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  kbb_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  lbb_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  mbb_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  nbb_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  obb_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  pbb_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  qbb_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  rbb_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  sbb_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  tbb_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ubb_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  vbb_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  wbb_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  xbb_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ybb_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  acb_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  bcb_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ccb_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  dcb_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  ecb_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  fcb_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  gcb_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
                        t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                        &b);
  hcb_CompactRegressionTree_Compa(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, t0_NodeMean, b_expl_temp, c_expl_temp,
    d_expl_temp);
  return b_predictOneWithCache(Xin, &Yfit, &cachedWeights, t0_CutPredictorIndex,
    t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean, &b);
}

/* End of code generation (CompactRegressionEnsemble.c) */
