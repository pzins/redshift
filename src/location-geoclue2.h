/* location-geoclue2.h -- Geoclue2 location provider header
   This file is part of Redshift.

   Redshift is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Redshift is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Redshift.  If not, see <http://www.gnu.org/licenses/>.

   Copyright (c) 2014-2017  Jon Lund Steffensen <jonlst@gmail.com>
*/

#ifndef REDSHIFT_LOCATION_GEOCLUE2_H
#define REDSHIFT_LOCATION_GEOCLUE2_H

#include <stdio.h>

#include <glib.h>

#include "redshift.h"

typedef struct {
	GMainLoop *loop;
	GThread *thread;
	GMutex lock;
	int pipe_fd_read;
	int pipe_fd_write;
	int available;
	int error;
	float latitude;
	float longitude;
} location_geoclue2_state_t;


int location_geoclue2_init(location_geoclue2_state_t *state);
int location_geoclue2_start(location_geoclue2_state_t *state);
void location_geoclue2_free(location_geoclue2_state_t *state);

void location_geoclue2_print_help(FILE *f);
int location_geoclue2_set_option(location_geoclue2_state_t *state,
				 const char *key, const char *value);

int location_geoclue2_get_fd(location_geoclue2_state_t *state);
int location_geoclue2_handle(location_geoclue2_state_t *state,
			     location_t *location, int *available);


#endif /* ! REDSHIFT_LOCATION_GEOCLUE2_H */
