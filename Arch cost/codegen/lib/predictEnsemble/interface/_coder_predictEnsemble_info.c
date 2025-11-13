/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * _coder_predictEnsemble_info.c
 *
 * Code generation for function 'predictEnsemble'
 *
 */

/* Include files */
#include "_coder_predictEnsemble_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void);

/* Function Definitions */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void)
{
  const mxArray *nameCaptureInfo;
  const char_T *data[6] = {
      "789cdd96cf6ed3301cc75d18880bd013670ed32ea0086dfca9760075a163055a869a2a9a"
      "ea893989bb66d871663b5578036ebcc21e8007408803074edc9038f2"
      "260889268dd33652946a1199e8ef50e7d76feccfcf3fd75f15d4da9d1a00e00698c6d7fa"
      "74bc9ee4490a2e81c5c8eab564bc9cc9555c016b0bf394fe21196de6",
      "491cca69e2218ad3990ea3ae873c69bcf331e0583032c64eac0c5d820d97e2de7cd28d32"
      "ba3b27a5492445cffa08db6f7b01057c24661592f924edc751ce7ed7"
      "0afa918d6c3fb2ef299e7f4e9e5aff66014fe93ec78e6bcb962730b5082ebd5fc5bb9acb"
      "9f2a0e0b225cca3b2bc97b92cb5bd407ad437d1bf605e622fe844f99",
      "1d50ec49013b4de365730736b93dba6d332161a6371a2561617f545f8beacd8eb3f7afc5"
      "e3f7deaf58aa8a77f7f5eec72a792a2e8a17e6acb7ecefed560eaf9e"
      "d10ff4078fcc46284fb6d87884c20e37c9f15e6b56c77e01a7a80e909357b5fe51cefc7f"
      "e58babce3b3b274fadffb880a7f4417f791fc48901bea1ccc144a348",
      "56776fbf55ec83bfbffcd8a892a762d57dd0dc3b7df88a8d2d5b364e77865b9ba68eac17"
      "cf56c7073fe5cc5fb68ffd9cf5eb197dd0d60fd7273790208b3326d7"
      "a1648c582c8442a2c9ddb5091282e3637867f64430e29eeb45df4dee2f873aa33eb2e5fe"
      "f4df0de31a9ddbc7fb92fbd828d887d255799aaa4e8b8b0ba44b8466",
      "70e48921e3f4e27cb8ec79f60a784a1fb4bb25cf336e194c5b169f66757eb2fdf967a5fe"
      "0ce01f52292f8955f7e7e7c83002e498dcea4afffe4123bcb7c9b8fe"
      "fffbf35f0fa7edd0",
      ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 4312U, &nameCaptureInfo);
  return nameCaptureInfo;
}

mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xEntryPoints;
  mxArray *xInputs;
  mxArray *xResult;
  const char_T *epFieldName[7] = {
      "QualifiedName",    "NumberOfInputs", "NumberOfOutputs", "ConstantInputs",
      "ResolvedFilePath", "TimeStamp",      "Visible"};
  const char_T *propFieldName[7] = {
      "Version",      "ResolvedFunctions", "Checksum", "EntryPoints",
      "CoverageInfo", "IsPolymorphic",     "AuxData"};
  uint8_T v[216] = {
      0U,   1U,   73U,  77U,  0U,   0U,   0U,   0U,   14U,  0U,   0U,   0U,
      200U, 0U,   0U,   0U,   6U,   0U,   0U,   0U,   8U,   0U,   0U,   0U,
      2U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,   5U,   0U,   0U,   0U,
      8U,   0U,   0U,   0U,   1U,   0U,   0U,   0U,   1U,   0U,   0U,   0U,
      1U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,   5U,   0U,   4U,   0U,
      17U,  0U,   0U,   0U,   1U,   0U,   0U,   0U,   17U,  0U,   0U,   0U,
      67U,  108U, 97U,  115U, 115U, 69U,  110U, 116U, 114U, 121U, 80U,  111U,
      105U, 110U, 116U, 115U, 0U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,
      14U,  0U,   0U,   0U,   112U, 0U,   0U,   0U,   6U,   0U,   0U,   0U,
      8U,   0U,   0U,   0U,   2U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,
      5U,   0U,   0U,   0U,   8U,   0U,   0U,   0U,   1U,   0U,   0U,   0U,
      0U,   0U,   0U,   0U,   1U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,
      5U,   0U,   4U,   0U,   14U,  0U,   0U,   0U,   1U,   0U,   0U,   0U,
      56U,  0U,   0U,   0U,   81U,  117U, 97U,  108U, 105U, 102U, 105U, 101U,
      100U, 78U,  97U,  109U, 101U, 0U,   77U,  101U, 116U, 104U, 111U, 100U,
      115U, 0U,   0U,   0U,   0U,   0U,   0U,   0U,   80U,  114U, 111U, 112U,
      101U, 114U, 116U, 105U, 101U, 115U, 0U,   0U,   0U,   0U,   72U,  97U,
      110U, 100U, 108U, 101U, 0U,   0U,   0U,   0U,   0U,   0U,   0U,   0U};
  xEntryPoints =
      emlrtCreateStructMatrix(1, 1, 7, (const char_T **)&epFieldName[0]);
  xInputs = emlrtCreateLogicalMatrix(1, 1);
  emlrtSetField(xEntryPoints, 0, "QualifiedName",
                emlrtMxCreateString("predictEnsemble"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "ResolvedFilePath",
                emlrtMxCreateString("C:\\Users\\User\\Documents\\MATLAB\\Arch "
                                    "cost\\predictEnsemble.mlx"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(739933.82737268519));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 7, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("25.2.0.3042426 (R2025b) Update 1"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)c_emlrtMexFcnResolvedFunctionsI());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("Wn6sJBQxOZLfVm7zgNoWfE"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  emlrtSetField(xResult, 0, "AuxData",
                emlrtMxCreateRowVectorUINT8((const uint8_T *)&v, 216U));
  return xResult;
}

/* End of code generation (_coder_predictEnsemble_info.c) */
