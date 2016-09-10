/*
 * Copyright (C)2005-2016 Haxe Foundation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */
#ifndef HLC_H
#define HLC_H

#include <math.h>
#include <hl.h>

#ifdef HL_64
#	define PAD_64_VAL	,0
#else
#	define PAD_64_VAL
#endif

#ifdef HLC_BOOT

// undefine some commonly used names that can clash with class/var name
#undef CONST
#undef stdin
#undef stdout
#undef stderr

// disable some warnings triggered by HLC code generator

#ifdef HL_VCC
#	pragma warning(disable:4702) // unreachable code 
#	pragma warning(disable:4100) // unreferenced param
#	pragma warning(disable:4101) // unreferenced local var
#	pragma warning(disable:4723) // potential divide by 0
#else
#	pragma GCC diagnostic ignored "-Wunused-variable"
#	pragma GCC diagnostic ignored "-Wunused-function"
#	pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#	pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#	pragma GCC diagnostic ignored "-Wcomment" // comment in comment
#endif

static void hl_null_access() {
	hl_error_msg(USTR("Null access"));
}

#endif

extern void *hlc_static_call(void *fun, hl_type *t, void **args, vdynamic *out);
extern void *hlc_get_wrapper(hl_type *t);
extern void hl_entry_point();

#endif