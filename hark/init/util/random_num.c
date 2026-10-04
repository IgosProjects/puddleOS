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

#include <util/random_num.h>

unsigned long int next = 1;  // NB: "unsigned long int" is assumed to be 32 bits wide

// returns a random number based on the seed set by "srand"
int rand(void)  // RAND_MAX assumed to be 32767
{
    next = next * 1103515245 + 12345;
    return (unsigned int) (next / 65536) % 32768;
}

// sets the seed used for "rand"
void srand(unsigned int seed)
{
    next = seed;
}