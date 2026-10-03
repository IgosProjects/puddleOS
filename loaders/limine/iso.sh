SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"

# create a new folder for this

mkdir limine_img
cd limine_img

# download the latest Limine prebuilt binary from github

curl -fL -o limine-binary.tar.gz https://github.com/Limine-Bootloader/Limine/releases/latest/download/limine-binary.tar.gz
gunzip < limine-binary.tar.gz | tar -xf -

# build the 'limine' utility

make -C limine-binary

# create a directory to be our iso root

mkdir -p iso_root

# copy the files over

mkdir -p iso_root/boot
cp -v ../hark64.elf iso_root/boot/hark64
mkdir -p iso_root/boot/limine
cp -v "$SCRIPT_DIR"/limine.conf limine-binary/limine-bios.sys limine-binary/limine-bios-cd.bin \
      limine-binary/limine-uefi-cd.bin iso_root/boot/limine/

# create an efi directory and copy over the files

mkdir -p iso_root/EFI/BOOT
cp -v limine-binary/BOOTX64.EFI iso_root/EFI/BOOT/
cp -v limine-binary/BOOTIA32.EFI iso_root/EFI/BOOT/

# create an ISO

xorriso -as mkisofs -R -r -J -b boot/limine/limine-bios-cd.bin \
        -no-emul-boot -boot-load-size 4 -boot-info-table -hfsplus \
        -apm-block-size 2048 --efi-boot boot/limine/limine-uefi-cd.bin \
        -efi-boot-part --efi-boot-image --protective-msdos-label \
        iso_root -o ../image.iso

# install stage 1 and 2 for BIOS

./limine-binary/limine bios-install ../image.iso