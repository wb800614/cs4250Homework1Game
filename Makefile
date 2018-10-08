# To use this Makefile, you type:
#
#        make 
#                  
# Libraries are assumed to be in the default search paths
# as are any required include files

# last-modified: last-modified: Fri Oct 25 15:20:14 2013

# Assumes the following file exists in the proper place.
include /Users/wesleybook/Desktop/Fall2018/cs4250/setup/Makefile.defs

# First target in the makefile will be used if you simply type make
# with no arguments. 
# animate is the executable to be created.
animate: animate.cc square.o object.o scene.o gun.o dart.o
	$(CC) animate.cc  $(InitShader) scene.o square.o object.o gun.o dart.o $(OPTIONS) $(LDLIBS) -o animate

# One pattern for each other file to be compiled.  These will be
# object files (i.e. .o files) Notice that only the options arguments
# are passed, not the LDLIBS as there will be no linking done for the
# .o files.
square.o: square.h square.cc object.h
	$(CC) square.cc -c $(OPTIONS)

object.o: object.h object.cc
	$(CC) object.cc -c $(OPTIONS)

scene.o: scene.h scene.cc
	$(CC) scene.cc -c $(OPTIONS)

gun.o: gun.h gun.cc
	$(CC) gun.cc -c $(OPTIONS)

dart.o: dart.h dart.cc
	$(CC) dart.cc -c $(OPTIONS)

# clean up after yourself
clean: 
	rm -f animate square.o circle.o object.o scene.o gun.o dart.o
