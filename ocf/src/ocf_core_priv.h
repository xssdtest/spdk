/*
 * Copyright(c) 2012-2018 Intel Corporation
 * SPDX-License-Identifier: BSD-3-Clause-Clear
 */

#ifndef __OCF_CORE_PRIV_H__
#define __OCF_CORE_PRIV_H__

#include "ocf/ocf.h"
#include "ocf_env.h"
#include "ocf_ctx_priv.h"
#include "ocf_volume_priv.h"

#define ocf_core_log_prefix(core, lvl, prefix, fmt, ...) \
	ocf_cache_log_prefix(ocf_core_get_cache(core), lvl, ".%s" prefix, \
			fmt, ocf_core_get_name(core), ##__VA_ARGS__)

#define ocf_core_log(core, lvl, fmt, ...) \
	ocf_core_log_prefix(core, lvl, ": ", fmt, ##__VA_ARGS__)

struct ocf_core_io {
	bool dirty;
	/*!< Indicates if io leaves dirty data  */

	struct ocf_request *req;
	ctx_data_t *data;

	log_sid_t sid;
	/*!< Sequence ID */

	uint64_t timestamp;
	/*!< Timestamp */
};

struct ocf_metadata_uuid {
	uint32_t size;
	uint8_t data[OCF_VOLUME_UUID_MAX_SIZE];
} __packed;

#define OCF_CORE_USER_DATA_SIZE 64

struct ocf_core_meta_config {
	uint8_t type;

	/* This bit means that object was added into cache */
	uint32_t added : 1;

	/* Core sequence number used to correlate cache lines with cores
	 * when recovering from atomic device */
	ocf_seq_no_t seq_no;

	/* Sequential cutoff threshold (in bytes) */
	uint32_t seq_cutoff_threshold;

	/* Sequential cutoff policy */
	ocf_seq_cutoff_policy seq_cutoff_policy;

	/* core object size in bytes */
	uint64_t length;

	uint8_t user_data[OCF_CORE_USER_DATA_SIZE];
};

struct ocf_core_meta_runtime {
	/* Number of blocks from that objects that currently are cached
	 * on the caching device.
	 */
	env_atomic cached_clines;
	env_atomic dirty_clines;
	env_atomic initial_dirty_clines;

	env_atomic64 dirty_since;

	struct {
		/* clines within lru list (?) */
		env_atomic cached_clines;
		/* dirty clines assigned to this specific partition within
		 * cache device
		 */
		env_atomic dirty_clines;
	} part_counters[OCF_IO_CLASS_MAX];
};


struct ocf_core {
	char name[OCF_CORE_NAME_SIZE];

	struct ocf_volume front_volume;
	struct ocf_volume volume;

	struct ocf_core_meta_config *conf_meta;
	struct ocf_core_meta_runtime *runtime_meta;

	struct {
		uint64_t last;
		uint64_t bytes;
		int rw;
	} seq_cutoff;

	env_atomic flushed;

	/* This bit means that object is open*/
	uint32_t opened : 1;

	struct ocf_counters_core *counters;
};

bool ocf_core_is_valid(ocf_cache_t cache, ocf_core_id_t id);

int ocf_core_volume_type_init(ocf_ctx_t ctx);

void ocf_core_volume_type_deinit(ocf_ctx_t ctx);

#define for_each_core_all(_cache, _core, _id) \
	for (_id = 0; _core = &cache->core[_id], _id < OCF_CORE_MAX; _id++)

#define for_each_core(_cache, _core, _id) \
	for_each_core_all(_cache, _core, _id) \
		if (core->conf_meta->added)

#endif /* __OCF_CORE_PRIV_H__ */
