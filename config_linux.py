
## This is the linux configuration file
# use 'scons -h' to see the list of command line options available

# Compiler flags (based on Debian's installation of lua)
LINKFLAGS = ['-L/usr/lib/x86_64-linux-gnu/']
CCFLAGS = ['-I/usr/include/lua5.1', '-g', '-ansi', '-Wall', '-fPIC', '-std=c99']
#CCFLAGS = ['-I/usr/include/lua50', '-g']

# this is the default directory for installation. Files will be installed on
# <prefix>/bin, <prefix>/lib and <prefix>/include when you run 'scons install'
#
# You can also specify this directory on the command line with the 'prefix'
# option
#
# You can see more 'generic' options for POSIX systems on config_posix.py

prefix = '/usr/local'

# libraries (based on Debian's installation of lua)
LIBS = ['lua5.1', 'dl', 'm']

