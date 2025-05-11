/*
 * Copyright(c) 2012-2018 Intel Corporation
 * SPDX-License-Identifier: BSD-3-Clause-Clear
 */

/**
 * @file
 * @brief OCF core API
 */

#ifndef __OCF_CORE_H__
#define __OCF_CORE_H__

#include "ocf_types.h"
#include "ocf_volume.h"
#include "ocf_io.h"
#include "ocf_mngt.h"

/**
 * @brief Obtain cache object from core
 *
 * @param[in] core Core object
 *
 * @retval Cache object
 */
ocf_cache_t ocf_core_get_cache(ocf_core_t core);

/**
 * @brief Obtain volume associated with core
 *
 * @param[in] core Core object
 *
 * @retval Volume
 */
ocf_volume_t ocf_core_get_volume(ocf_core_t core);

/**
 * @brief Obtain volume of the core
 *
 * @param[in] core Core object
 *
 * @retval Front volume
 */
ocf_volume_t ocf_core_get_front_volume(ocf_core_t core);

/**
 * @brief Get UUID of volume associated with core
 *
 * @param[in] core Core object
 *
 * @retval Volume UUID
 */
static inline const struct ocf_volume_uuid *ocf_core_get_uuid(ocf_core_t core)
{
	return ocf_volume_get_uuid(ocf_core_get_volume(core));
}

/**
 * @brief Get sequential cutoff threshold of given core object
 *
 * @param[in] core Core object
 *
 * @retval Sequential cutoff threshold [B]
 */
uint32_t ocf_core_get_seq_cutoff_threshold(ocf_core_t core);

/**
 * @brief Get sequential cutoff policy of given core object
 *
 * @param[in] core Core object
 *
 * @retval Sequential cutoff policy
 */
ocf_seq_cutoff_policy ocf_core_get_seq_cutoff_policy(ocf_core_t core);

/**
 * @brief Get ID of given core object
 *
 * @param[in] core Core object
 *
 * @retval Core ID
 */
ocf_core_id_t ocf_core_get_id(ocf_core_t core);

/**
 * @brief Set name of given core object
 *
 * @param[in] core Core object
 * @param[in] src Source of Core name
 * @param[in] src_size Size of src
 *
 * @retval 0 Success
 * @retval Non-zero Fail
 */
int ocf_core_set_name(ocf_core_t core, const char *src, size_t src_size);

/**
 * @brief Get name of given core object
 *
 * @param[in] core Core object
 *
 * @retval Core name
 */
const char *ocf_core_get_name(ocf_core_t core);

/**
 * @brief Get core state
 *
 * @param[in] core Core object
 *
 * @retval Core state
 */
ocf_core_state_t ocf_core_get_state(ocf_core_t core);

/**
 * @brief Obtain core object of given ID from cache
 *
 * @param[in] cache Cache object
 * @param[in] id Core ID
 * @param[out] core Core object
 *
 * @retval 0 Success
 * @retval Non-zero Core getting failed
 */
int ocf_core_get(ocf_cache_t cache, ocf_core_id_t id, ocf_core_t *core);

/**
 * @brief Allocate new ocf_io
 *
 * @param[in] core Core object
 *
 * @retval ocf_io object
 */
static inline struct ocf_io *ocf_core_new_io(ocf_core_t core)
{
	ocf_volume_t volume = ocf_core_get_front_volume(core);

	return ocf_volume_new_io(volume);
}

/**
 * @brief Submit ocf_io
 *
 * @param[in] io IO to be submitted
 * @param[in] mode Cache mode to be enforced
 */
void ocf_core_submit_io_mode(struct ocf_io *io, ocf_cache_mode_t cache_mode);

/**
 * @brief Submit ocf_io
 *
 * @param[in] io IO to be submitted
 */
static inline void ocf_core_submit_io(struct ocf_io *io)
{
	ocf_volume_submit_io(io);
}

/**
 * @brief Fast path for submitting IO. If possible, request is processed
 * immediately without adding to internal request queue
 *
 * @param[in] io IO to be submitted
 *
 * @retval 0 IO has been submitted successfully
 * @retval Non-zero Fast submit failed. Try to submit IO with ocf_submit_io()
 */
int ocf_core_submit_io_fast(struct ocf_io *io);

/**
 * @brief Submit ocf_io with flush command
 *
 * @param[in] io IO to be submitted
 */
static inline void ocf_core_submit_flush(struct ocf_io *io)
{
	ocf_volume_submit_flush(io);
}

/**
 * @brief Submit ocf_io with discard command
 *
 * @param[in] io IO to be submitted
 */
static inline void ocf_core_submit_discard(struct ocf_io *io)
{
	ocf_volume_submit_discard(io);
}

/**
 * @brief Core visitor function type which is called back when iterating over
 * cores.
 *
 * @param[in] core Core which is currently iterated (visited)
 * @param[in] cntx Visitor context
 *
 * @retval 0 continue visiting cores
 * @retval Non-zero stop iterating and return result
 */
typedef int (*ocf_core_visitor_t)(ocf_core_t core, void *cntx);

/**
 * @brief Run visitor function for each core of given cache
 *
 * @param[in] cache OCF cache instance
 * @param[in] visitor Visitor function
 * @param[in] cntx Visitor context
 * @param[in] only_opened Visit only opened cores
 *
 * @retval 0 Success
 * @retval Non-zero Fail
 */
int ocf_core_visit(ocf_cache_t cache, ocf_core_visitor_t visitor, void *cntx,
		bool only_opened);

#endif /* __OCF_CORE_H__ */
