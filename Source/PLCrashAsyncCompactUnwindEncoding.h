/*
 * Copyright (c) 2013 Plausible Labs Cooperative, Inc.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef PLCRASH_ASYNC_COMPACT_UNWIND_ENCODING_H
#define PLCRASH_ASYNC_COMPACT_UNWIND_ENCODING_H 1

#include "PLCrashAsync.h"
#include "PLCrashAsyncImageList.h"

#include <mach-o/compact_unwind_encoding.h>

/**
 * @internal
 * @ingroup plcrash_async_cfe
 * @{
 */

/**
 * A CFE reader instance. Performs CFE data parsing from a backing memory object.
 */
typedef struct plcrash_async_cfe_reader {
    /** A memory object containing the CFE data at the starting address. */
    plcrash_async_mobject_t *mobj;

    /** The target CPU type. */
    cpu_type_t cputype;

    /** The unwind info header. Note that the header values may require byte-swapping for the local process' use. */
    struct unwind_info_section_header header;

    /** The byte order of the encoded data (including the header). */
    const plcrash_async_byteorder_t *byteorder;
} plcrash_async_cfe_reader_t;

plcrash_error_t plcrash_async_cfe_reader_init (plcrash_async_cfe_reader_t *reader, plcrash_async_mobject_t *mobj, cpu_type_t cputype);

plcrash_error_t plcrash_async_cfe_reader_find_pc (plcrash_async_cfe_reader_t *reader, pl_vm_address_t pc, uint32_t *encoding);

void plcrash_async_cfe_reader_free (plcrash_async_cfe_reader_t *reader);

/**
 * @} plcrash_async_cfe
 */

#endif /* PLCRASH_ASYNC_COMPACT_UNWIND_ENCODING_H */