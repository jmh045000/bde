// bslmf_isconst.h                                                    -*-C++-*-
#ifndef INCLUDED_BSLMF_ISCONST
#define INCLUDED_BSLMF_ISCONST

#ifndef INCLUDED_BSLS_IDENT
#include <bsls_ident.h>
#endif
BSLS_IDENT("$Id: $")

//@PURPOSE: Provide a compile-time check for 'const'-qualified types.
//
//@CLASSES:
//  bsl::is_const: meta-function for determining 'const'-qualified types
//
//@SEE_ALSO: bslmf_integralconstant
//
//@DESCRIPTION: This component defines a meta-function, 'bsl::is_const', that
// may be used to query whether a type is 'const'-qualified as defined in the
// C++11 standard [basic.type.qualifier].
//
// 'bsl::is_const' meets the requirements of the 'is_const' template defined in
// the C++11 standard [meta.unary.prop].
//
///Usage
///-----
// In this section we show intended use of this component.
//
///Example 1: Verify 'Const' Types
///- - - - - - - - - - - - - - - -
// Suppose that we want to assert whether a particular type is
// 'const'-qualified.
//
// First, we create two 'typedef's -- a 'const'-qualified type and an
// unqualified type:
//..
//  typedef int        MyType;
//  typedef const int  MyConstType;
//..
// Now, we instantiate the 'bsl::is_const' template for each of the
// 'typedef's and assert the 'value' static data member of each instantiation:
//..
//  assert(false == bsl::is_const<MyType>::value);
//  assert(true  == bsl::is_const<MyConstType>::value);
//..

#ifndef INCLUDED_BSLSCM_VERSION
#include <bslscm_version.h>
#endif

#ifndef INCLUDED_BSLMF_INTEGRALCONSTANT
#include <bslmf_integralconstant.h>
#endif

namespace bsl {

                         // ===============
                         // struct is_const
                         // ===============

template <class TYPE>
struct is_const : false_type {
    // This 'struct' template implements the 'is_const' meta-function defined
    // in the C++11 standard [meta.unary.cat] to determine if the (template
    // parameter) 'TYPE' is 'const'-qualified.  This 'struct' derives from
    // 'bsl::true_type' if the 'TYPE' is 'const'-qualified, and
    // 'bsl::false_type' otherwise.  Note that this generic default template
    // derives from 'bsl::false_type'.  A template specialization is provided
    // (below) that derives from 'bsl::true_type'.
};

                         // ===========================
                         // struct is_const<TYPE const>
                         // ===========================

template <class TYPE>
struct is_const<TYPE const> : true_type {
     // This partial specialization of 'is_const', for when the (template
     // parameter) 'TYPE' is 'const'-qualified, derives from 'bsl::true_type'.
};

}  // close namespace bsl

#endif

// ----------------------------------------------------------------------------
// Copyright 2013 Bloomberg Finance L.P.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// ----------------------------- END-OF-FILE ----------------------------------
