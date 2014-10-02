// bdldfp_intelimpwrapper.h                                           -*-C++-*-
#ifndef INCLUDED_BDLDFP_INTELIMPWRAPPER
#define INCLUDED_BDLDFP_INTELIMPWRAPPER

#ifndef INCLUDED_BSLS_IDENT
#include <bsls_ident.h>
#endif
BSLS_IDENT("$Id$")

//@PURPOSE: Provide a central mechanism to configure the Intel DFP library.
//
//@CLASSES:
//
//@SEE_ALSO: bdldfp_decimalimputil_inteldfp, bdldfp_decimalplatform
//
//@DESCRIPTION: This component provides a centralized mechanism to include the
// requesite Intel DFP headers, by issuing the appropriate '#define'
// configuration macros before including the intel headers.  This component is
// for internal use only by the 'bdldfp_decimal*' components.  Direct use of
// any names declared in this component by any other code invokes undefined
// behavior.  In other words: this code may change, disappear, break, move
// without notice, and no support whatsoever will ever be provided for it.
//
///Usage
///-----
// This section shows the intended use of this component.

#ifndef INCLUDED_BDLSCM_VERSION
#include <bdlscm_version.h>
#endif

#ifndef INCLUDED_BDLDFP_DECIMALPLATFORM
#include <bdldfp_decimalplatform.h>
#define INCLUDED_BDLDFP_DECIMALPLATFORM
#endif

#ifndef INCLUDED_BSLS_PLATFORM
#include <bsls_platform.h>
#endif

#if !defined(BSLS_PLATFORM_OS_WINDOWS)

#  if !defined(INCLUDED_BID_FUNCTIONS) \
   && !defined(INCLUDED_BID_CONF) \
   && !defined(INCLUDED_BID_INTERNAL)

// Controlling macros for the intel library configuration

#    define DECIMAL_CALL_BY_REFERENCE      0
#    define DECIMAL_GLOBAL_ROUNDING        1
#    define DECIMAL_GLOBAL_EXCEPTION_FLAGS 1
#    ifndef LINUX
#      define LINUX
#      define BDLDFP_INTELIMPWRAPPER_FAKE_DEFINE_LINUX
#    endif

#    ifdef BSLS_PLATFORM_IS_BIG_ENDIAN
#      define BID_BIG_ENDIAN 1
#    else
#      define BID_BIG_ENDIAN 0
#    endif

// The IBM compiler has trouble with the embedded '__thread' token, under some
// build modes.  We'll turn it off, for now.  We'll do so for Sun also, since
// it is disabled in the wrapper-package for that compiler as well.

#    if defined(BSLS_PLATFORM_CMP_IBM) || defined(BSLS_PLATFORM_CMP_SUN)
#      define __thread
#    endif

// In C++, there's always a 'wchar_t' type, so we need to tell Intel's library
// about this.

#    define _WCHAR_T_DEFINED

     extern "C" {
#     include <bid_conf.h>
#     include <bid_functions.h>
#     include <bid_internal.h>
     }

// Intel #define's several symbols we don't want to leak out.

#    undef P7
#    undef P16
#    undef P34

#    undef DECIMAL_CALL_BY_REFERENCE
#    undef DECIMAL_GLOBAL_ROUNDING
#    undef DECIMAL_GLOBAL_EXCEPTION_FLAGS
#    undef _WCHAR_T_DEFINED

#    ifdef BDLDFP_INTELIMPWRAPPER_FAKE_DEFINE_LINUX
#      undef LINUX
#      undef BDLDFP_INTELIMPWRAPPER_FAKE_DEFINE_LINUX
#    endif

#    define INCLUDED_BID_CONF
#    define INCLUDED_BID_FUNCTIONS
#    define INCLUDED_BID_INTERNAL
#  endif

#endif // if !defined(BSLS_PLATFORM_OS_WINDOWS)

#endif

// ----------------------------------------------------------------------------
// Copyright 2014 Bloomberg Finance L.P.
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
