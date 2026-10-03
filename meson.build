# define puddleOS project
project('puddleOS', 'c', 'nasm',
  default_options: [
    'c_std=c23',
    'optimization=2',
    'warning_level=3'
  ]
)

# define architecture things
hark_arch = 'x86_64'
hark_arch_dir = 'hark/arch' / hark_arch
hark_arch_linker_script = hark_arch_dir / 'linker.ld'

# define includes
hark_includes = [
  include_directories('hark/include'),
  include_directories(hark_arch_dir / 'include')
]

# define linker arguments
# stolen from old gooseOS
hark_link_args = [
    '-nostdlib',
    '-static',
    '-fno-pie',
    '-T', meson.current_source_dir() / hark_arch_linker_script
]

# this should supply hark_sources
subdir('hark')

# this should supply hark_arch_sources
subdir(hark_arch_dir)

hark_kernel = executable(
  'hark64.elf',
  sources: hark_sources + hark_arch_sources,
  include_directories: hark_includes,
  link_args: hark_link_args,
  link_depends: hark_arch_linker_script
)
