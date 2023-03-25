/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright 2020 Google, Inc
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __GOOGLE_LOGBUFFER_H_
#define __GOOGLE_LOGBUFFER_H_

#include <stdarg.h>

struct logbuffer;
#if IS_ENABLED(CONFIG_GOOGLE_LOGBUFFER)
void logbuffer_log(struct logbuffer *instance, const char *fmt, ...);
void logbuffer_vlog(struct logbuffer *instance, const char *fmt,
		    va_list args);
/*
 * Registers a new log buffer entry.
 * param name: name of the file in the /d/logbuffer/ directory.
 * returns the pointer to the logbuffer metadata.
 */
struct logbuffer *logbuffer_register(char *name);

void logbuffer_unregister(struct logbuffer *instance);
#else
void logbuffer_log(struct logbuffer *instance, const char *fmt, ...)
{
	return;
}
void logbuffer_vlog(struct logbuffer *instance, const char *fmt,
		    va_list args)
{
	return;
}
struct logbuffer *logbuffer_register(char *name)
{
	return NULL;
}
void logbuffer_unregister(struct logbuffer *instance)
{
	return;
}
#endif
#endif /* __GOOGLE_LOGBUFFER_H_ */

