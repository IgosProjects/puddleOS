; *
; * Copyright 2026 gooseFoundation and the HARK kernel contibutors
; *
; * Licensed under the Apache License, Version 2.0 (the "License");
; * you may not use this file except in compliance with the License.
; * You may obtain a copy of the License at
; *
; *     https://www.apache.org/licenses/LICENSE-2.0
; *
; * Unless required by applicable law or agreed to in writing, software
; * distributed under the License is distributed on an "AS IS" BASIS,
; * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
; * See the License for the specific language governing permissions and
; * limitations under the License.
; *

; this file defines the get_cpu_time function used by the OS

[BITS 64]

global get_cpu_time

; returns the current amount of CPU ticks supplied by the timer
get_cpu_time:
    rdtsc ; read the TSC clock
    shl rdx, 32 ; shift higher into the 64 bit reg
    or  rax, rdx ; combine RAX with RDX
    ret 