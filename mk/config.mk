#
#  BSD LICENSE
#
#  Copyright (c) Intel Corporation.
#  All rights reserved.
#
#  Redistribution and use in source and binary forms, with or without
#  modification, are permitted provided that the following conditions
#  are met:
#
#    * Redistributions of source code must retain the above copyright
#      notice, this list of conditions and the following disclaimer.
#    * Redistributions in binary form must reproduce the above copyright
#      notice, this list of conditions and the following disclaimer in
#      the documentation and/or other materials provided with the
#      distribution.
#    * Neither the name of Intel Corporation nor the names of its
#      contributors may be used to endorse or promote products derived
#      from this software without specific prior written permission.
#
#  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
#  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
#  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
#  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
#  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
#  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
#  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
#  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
#  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
#  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
#  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#

# Installation prefix
CONFIG_PREFIX?=/usr/local

# Target architecture
CONFIG_ARCH?=native

# Prefix for cross compilation
CONFIG_CROSS_PREFIX?=

# Build with debug logging. Turn off for performance testing and normal usage
CONFIG_DEBUG?=n

# Build with support of backtrace printing in log messages. Requires libunwind.
CONFIG_LOG_BACKTRACE?=n

# Treat warnings as errors (fail the build on any warning).
CONFIG_WERROR?=n

# Build with link-time optimization.
CONFIG_LTO?=n

# Generate profile guided optimization data.
CONFIG_PGO_CAPTURE?=n

# Use profile guided optimization data.
CONFIG_PGO_USE?=n

# Build with code coverage instrumentation.
CONFIG_COVERAGE?=n

# Build with Address Sanitizer enabled
CONFIG_ASAN?=n

# Build with Undefined Behavior Sanitizer enabled
CONFIG_UBSAN?=n

# Build with Thread Sanitizer enabled
CONFIG_TSAN?=n

# Build tests
CONFIG_TESTS?=y

# Directory that contains the desired SPDK environment library.
# By default, this is implemented using DPDK.
CONFIG_ENV?=/home/hyc/xssdtest_ai/xt_platform/spdk/lib/env_dpdk

# This directory should contain 'include' and 'lib' directories for your DPDK
# installation.
CONFIG_DPDK_DIR?=/home/hyc/xssdtest_ai/xt_platform/spdk/dpdk/build

# Build SPDK FIO plugin. Requires CONFIG_FIO_SOURCE_DIR set to a valid
# fio source code directory.
CONFIG_FIO_PLUGIN?=n

# This directory should contain the source code directory for fio
# which is required for building the SPDK FIO plugin.
CONFIG_FIO_SOURCE_DIR?=

# Enable RDMA support for the NVMf target.
# Requires ibverbs development libraries.
CONFIG_RDMA?=n
CONFIG_RDMA_SEND_WITH_INVAL?=n

# Enable NVMe Character Devices.
CONFIG_NVME_CUSE?=n

# Enable FC support for the NVMf target.
# Requires FC low level driver (from FC vendor)
CONFIG_FC?=n
CONFIG_FC_PATH?=

# Build Ceph RBD support in bdev modules
# Requires librbd development libraries
CONFIG_RBD?=n

# Build vhost library.
CONFIG_VHOST?=y
CONFIG_VHOST_INTERNAL_LIB?=n

# Build vhost initiator (Virtio) driver.
CONFIG_VIRTIO?=y

# Build with PMDK backends
CONFIG_PMDK?=n
CONFIG_PMDK_DIR?=

# Enable the dependencies for building the compress vbdev
CONFIG_REDUCE?=n

# Build with VPP
CONFIG_VPP?=n
CONFIG_VPP_DIR?=

# Requires libiscsi development libraries.
CONFIG_ISCSI_INITIATOR?=n

# Enable the dependencies for building the crypto vbdev
CONFIG_CRYPTO?=n

# Build spdk shared libraries in addition to the static ones.
CONFIG_SHARED?=n

# Build with VTune suport.
CONFIG_VTUNE?=n
CONFIG_VTUNE_DIR?=

# Build the dpdk igb_uio driver
CONFIG_IGB_UIO_DRIVER?=n

# Build Intel IPSEC_MB library
CONFIG_IPSEC_MB?=n

# Enable OCF module
CONFIG_OCF?=n
CONFIG_OCF_PATH?=
CONFIG_CUSTOMOCF?=n

# Build ISA-L library
CONFIG_ISAL?=n

# Build with IO_URING support
CONFIG_URING?=n

# Path to custom built IO_URING library
CONFIG_URING_PATH?=

# Build with FUSE support
CONFIG_FUSE?=n
