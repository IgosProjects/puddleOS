/*
 * Copyright 2026 gooseFoundation and the HARK kernel contibutors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once
#include <stdint.h>

// clamps an integer value to the low value if its below and the high value if its above
static inline int clamp_int(int val, int low, int high) {
    if (val < low) return low;
    if (val > high) return high;
    return val;
}