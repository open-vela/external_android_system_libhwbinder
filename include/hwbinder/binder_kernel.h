/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ANDROID_HARDWARE_BINDER_KERNEL_H
#define ANDROID_HARDWARE_BINDER_KERNEL_H

#include <linux/android/binder.h>

/**
 * This file exists because the uapi kernel headers in bionic are built
 * from upstream kernel headers only, and not all of the hwbinder kernel changes
 * have made it upstream yet. Therefore, the modifications to the
 * binder header are added locally in this file.
 */

enum {
	BINDER_BUFFER_FLAG_REF          = 1U << 1,
};

enum {
        FLAT_BINDER_FLAG_SCHEDPOLICY_MASK = 0x600,
        FLAT_BINDER_FLAG_SCHEDPOLICY_SHIFT = 9,
        FLAT_BINDER_FLAG_INHERIT_RT = 0x800,
};

struct binder_node_info_for_ref {
        __u32            handle;
        __u32            strong_count;
        __u32            weak_count;
        __u32            reserved1;
        __u32            reserved2;
        __u32            reserved3;
};

#define BINDER_GET_NODE_INFO_FOR_REF	_IOWR('b', 12, struct binder_node_info_for_ref)

#endif // ANDROID_HARDWARE_BINDER_KERNEL_H
