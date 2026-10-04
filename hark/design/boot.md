# The boot process for a HARK based OS

HARK can be loaded by anything supported by the #preloader that is provided in the kernel.
For example, the preloader for the kernel will support Limine and possibly Multiboot2 in the future

## PRELOADER(UNIMPLEMENTED CURRENTLY!)

The preloader is a piece of code that runs even before the kernel enters k_entry, it's responsible for translating the bootprotocol's structures into HARK's structures, so from the Limine framebuffer into `hark_fb`

## KERNEL ENTRY

This is where the kernel actually starts setting up the OS and booting, the entry(`k_entry`) starts the required drivers and loads the needed things to enter userspace and start user code
