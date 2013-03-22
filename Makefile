# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/elgabart/cloned/spindynamics

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/elgabart/cloned/spindynamics

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running interactive CMake command-line interface..."
	/usr/bin/cmake -i .
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: install/local
.PHONY : install/local/fast

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: install/strip
.PHONY : install/strip/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components
.PHONY : list_install_components/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/elgabart/cloned/spindynamics/CMakeFiles /home/elgabart/cloned/spindynamics/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/elgabart/cloned/spindynamics/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named hslib

# Build rule for target.
hslib: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 hslib
.PHONY : hslib

# fast build rule for target.
hslib/fast:
	$(MAKE) -f spinlib/CMakeFiles/hslib.dir/build.make spinlib/CMakeFiles/hslib.dir/build
.PHONY : hslib/fast

#=============================================================================
# Target rules for targets named hs-mpi

# Build rule for target.
hs-mpi: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 hs-mpi
.PHONY : hs-mpi

# fast build rule for target.
hs-mpi/fast:
	$(MAKE) -f mpi/CMakeFiles/hs-mpi.dir/build.make mpi/CMakeFiles/hs-mpi.dir/build
.PHONY : hs-mpi/fast

#=============================================================================
# Target rules for targets named hs

# Build rule for target.
hs: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 hs
.PHONY : hs

# fast build rule for target.
hs/fast:
	$(MAKE) -f non-mpi/CMakeFiles/hs.dir/build.make non-mpi/CMakeFiles/hs.dir/build
.PHONY : hs/fast

#=============================================================================
# Target rules for targets named convolute

# Build rule for target.
convolute: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 convolute
.PHONY : convolute

# fast build rule for target.
convolute/fast:
	$(MAKE) -f convolute/CMakeFiles/convolute.dir/build.make convolute/CMakeFiles/convolute.dir/build
.PHONY : convolute/fast

#=============================================================================
# Target rules for targets named bench_eigen

# Build rule for target.
bench_eigen: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 bench_eigen
.PHONY : bench_eigen

# fast build rule for target.
bench_eigen/fast:
	$(MAKE) -f dbg/CMakeFiles/bench_eigen.dir/build.make dbg/CMakeFiles/bench_eigen.dir/build
.PHONY : bench_eigen/fast

#=============================================================================
# Target rules for targets named euler

# Build rule for target.
euler: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 euler
.PHONY : euler

# fast build rule for target.
euler/fast:
	$(MAKE) -f dbg/CMakeFiles/euler.dir/build.make dbg/CMakeFiles/euler.dir/build
.PHONY : euler/fast

#=============================================================================
# Target rules for targets named grid

# Build rule for target.
grid: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 grid
.PHONY : grid

# fast build rule for target.
grid/fast:
	$(MAKE) -f dbg/CMakeFiles/grid.dir/build.make dbg/CMakeFiles/grid.dir/build
.PHONY : grid/fast

#=============================================================================
# Target rules for targets named hamiltonian

# Build rule for target.
hamiltonian: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 hamiltonian
.PHONY : hamiltonian

# fast build rule for target.
hamiltonian/fast:
	$(MAKE) -f dbg/CMakeFiles/hamiltonian.dir/build.make dbg/CMakeFiles/hamiltonian.dir/build
.PHONY : hamiltonian/fast

#=============================================================================
# Target rules for targets named memcheck

# Build rule for target.
memcheck: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 memcheck
.PHONY : memcheck

# fast build rule for target.
memcheck/fast:
	$(MAKE) -f dbg/CMakeFiles/memcheck.dir/build.make dbg/CMakeFiles/memcheck.dir/build
.PHONY : memcheck/fast

#=============================================================================
# Target rules for targets named orca

# Build rule for target.
orca: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 orca
.PHONY : orca

# fast build rule for target.
orca/fast:
	$(MAKE) -f dbg/CMakeFiles/orca.dir/build.make dbg/CMakeFiles/orca.dir/build
.PHONY : orca/fast

#=============================================================================
# Target rules for targets named orca2easy

# Build rule for target.
orca2easy: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 orca2easy
.PHONY : orca2easy

# fast build rule for target.
orca2easy/fast:
	$(MAKE) -f dbg/CMakeFiles/orca2easy.dir/build.make dbg/CMakeFiles/orca2easy.dir/build
.PHONY : orca2easy/fast

#=============================================================================
# Target rules for targets named orca2orca

# Build rule for target.
orca2orca: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 orca2orca
.PHONY : orca2orca

# fast build rule for target.
orca2orca/fast:
	$(MAKE) -f dbg/CMakeFiles/orca2orca.dir/build.make dbg/CMakeFiles/orca2orca.dir/build
.PHONY : orca2orca/fast

#=============================================================================
# Target rules for targets named resfield

# Build rule for target.
resfield: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 resfield
.PHONY : resfield

# fast build rule for target.
resfield/fast:
	$(MAKE) -f dbg/CMakeFiles/resfield.dir/build.make dbg/CMakeFiles/resfield.dir/build
.PHONY : resfield/fast

#=============================================================================
# Target rules for targets named lebedev

# Build rule for target.
lebedev: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 lebedev
.PHONY : lebedev

# fast build rule for target.
lebedev/fast:
	$(MAKE) -f lebedev/CMakeFiles/lebedev.dir/build.make lebedev/CMakeFiles/lebedev.dir/build
.PHONY : lebedev/fast

#=============================================================================
# Target rules for targets named powder

# Build rule for target.
powder: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 powder
.PHONY : powder

# fast build rule for target.
powder/fast:
	$(MAKE) -f powder/CMakeFiles/powder.dir/build.make powder/CMakeFiles/powder.dir/build
.PHONY : powder/fast

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... install"
	@echo "... install/local"
	@echo "... install/strip"
	@echo "... list_install_components"
	@echo "... rebuild_cache"
	@echo "... hslib"
	@echo "... hs-mpi"
	@echo "... hs"
	@echo "... convolute"
	@echo "... bench_eigen"
	@echo "... euler"
	@echo "... grid"
	@echo "... hamiltonian"
	@echo "... memcheck"
	@echo "... orca"
	@echo "... orca2easy"
	@echo "... orca2orca"
	@echo "... resfield"
	@echo "... lebedev"
	@echo "... powder"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

