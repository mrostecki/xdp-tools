/* SPDX-License-Identifier: GPL-2.0 */

#ifndef __STATS_H
#define __STATS_H

#include "libbpf.h"
#include "bpf/xdp_stats_kern_user.h"

struct record {
	__u64 timestamp;
	struct datarec total; /* defined in common_kern_user.h */
};

struct stats_record {
	struct record stats[XDP_ACTION_MAX];
};

void stats_print_one(struct stats_record *stats_rec);
void stats_print(struct stats_record *stats_rec,
                 struct stats_record *stats_prev);
int stats_collect(int map_fd, __u32 map_type,
                  struct stats_record *stats_rec);
int stats_poll(const char *pin_dir, const char *map_name, int interval);

#endif