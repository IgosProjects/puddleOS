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

; this file defines the basic OUTB, INB, OUTW and INW functions required to interface with the legacy x86 ports

[BITS 64]

global outb
global inb

global outw
global inw

; Send a 8 bit value down a port
outb:
    mov dx, di ; Read port argument into dx
    mov al, sil ; Read value argument into al
    out dx, al
    ret ; Return from function

; Read a 8 bit value from a port
inb:
    mov dx, di ; Read port argument into dx
    in al, dx ; Read into al
    movzx eax, al
    ret ; Return from function

; Send a 16 bit value down a port
outw:
    mov dx, di ; Read port value
    mov ax, si ; Read value
    out dx, ax
    ret ; Return from function

; Read a 16 bit value from a port
inw:
    mov dx, di ; Read port value
    in ax, dx
    ret ; Return from function