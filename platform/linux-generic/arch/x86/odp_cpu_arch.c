/* Copyright (c) 2015, Linaro Limited
 * All rights reserved.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 */

#include "config.h"

#include <odp_posix_extensions.h>

#include <odp/api/cpu.h>
#include <odp_debug_internal.h>

#include <time.h>

uint64_t odp_cpu_cycles(void)
{
	union {
		uint64_t tsc_64;
		struct {
			uint32_t lo_32;
			uint32_t hi_32;
		};
	} tsc;

	__asm__ __volatile__ ("rdtsc" :
		     "=a" (tsc.lo_32),
		     "=d" (tsc.hi_32) : : "memory");

	return tsc.tsc_64;
}
