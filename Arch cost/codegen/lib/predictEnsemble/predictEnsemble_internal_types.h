/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * predictEnsemble_internal_types.h
 *
 * Code generation for function 'predictEnsemble'
 *
 */

#ifndef PREDICTENSEMBLE_INTERNAL_TYPES_H
#define PREDICTENSEMBLE_INTERNAL_TYPES_H

/* Include files */
#include "predictEnsemble_types.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef c_enum_c_classreg_learning_code
#define c_enum_c_classreg_learning_code
enum c_classreg_learning_coderutils_
{
  Logit = 0, /* Default value */
  Doublelogit,
  Invlogit,
  Ismax,
  Sign,
  Symmetric,
  Symmetricismax,
  Symmetriclogit,
  Identity
};
#endif /* c_enum_c_classreg_learning_code */
#ifndef c_typedef_c_classreg_learning_c
#define c_typedef_c_classreg_learning_c
typedef enum c_classreg_learning_coderutils_ c_classreg_learning_coderutils_;
#endif /* c_typedef_c_classreg_learning_c */

#endif
/* End of code generation (predictEnsemble_internal_types.h) */
