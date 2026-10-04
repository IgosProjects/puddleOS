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

#include <stdio.h>
#include <util/random_num.h>
#include <asm/hcf.h>
#include <asm/cpu_timer.h>

#include <util/math.h>

const char* panicMessages[19] = {
    "oh noes!",
    "ded",
    "oh no! my OS has DIED!",
    "hehe",
    "uhhh, something crashed!",
    "banana",
    "${funny_message}",
    "please fix my code",
    "how could my great code break!",
    "the cpu is throwing a fit again!",
    "oppsie, i crashed",
    "huston we got a problem, we crashed!",
    "gdt init, not OK",
    "fix?",
    "${i_ran_out_of_ideas}",
    "r/softwaregore",
    "r/bluescreen or whatever its called",
    "r/something?",
    "puddleOS has decided to dry up and is now just 'OS'"
};

// internally used function that returns a value between 
int get_rand_between_needed_index(void) {
    // 0xFFFFFF is the max asumed value here
    unsigned int max_acceptable = 0xFFFFFFFF - (0xFFFFFFFF % 20);
    unsigned int raw;
    
    do {
        raw = (unsigned int)rand();
    } while (raw >= max_acceptable); // reject and fail if not the in range
    
    return raw % 20;
}

// stops the kernel and initiates a panic
// only use ON CRITICAL errors!
void kpanic(const char* reason) {
    // set the random seed
    srand(get_cpu_time());

    uint32_t messageToUse = get_rand_between_needed_index();

    // print the randomized panic message
    puts(panicMessages[messageToUse]);
    putc('\n');

    // now the actual panic

    puts("puddleOS has crashed with error: ");
    puts(reason);
    putc('\n');

    puts("please reboot your device!");

    // now stop the CPU
    hcf();
}