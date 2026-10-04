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

#include <stdint.h>
#include <util/config.h>
#include <drivers/kUART.h>
#include <stdio.h>
#include <util/random_num.h>
#include <asm/cpu_timer.h>
#include <asm/hcf.h>
#include <core/panic.h>

// main entry function that our assembly layer calls on boot
// responsible for kernel init
void k_entry() {
    // we are in very low level code, so low we dont even got a console!
    // so we must define that ourselves

    #if CONFIG_USE_UART == 1
        // initilize UART
        kUART_init();
    #endif
    
    puts("[kernel.init.early] Hello, World from k_entry!\n");
    
    // set random num seed using the CPU clock
    puts("[kernel.init.early] Setting random number seed to CPU clock value\n");
    srand(get_cpu_time()); // get_cpu_time returns ticks since boot, that is a "random" seed

    puts("[kernel.init.early] testing kpanic!\n");
    kpanic("idk?");

    puts("[kernel.init.early] Reached end of k_entry()! halting!\n");

    // stop the CPU
    hcf();
}