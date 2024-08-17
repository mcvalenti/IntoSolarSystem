----------------------------------------------
Proyect to incorporate SPICE NAIF/JPL library
----------------------------------------------
https://naif.jpl.nasa.gov/naif/utilities.html
https://naif.jpl.nasa.gov/naif/documentation.html
https://naif.jpl.nasa.gov/naif/n0067_example_kernels.html

Installation notes (Windows + Cygwin + Eclipse IDE):

* In Windows, download Cygwin-gcc-64 package (https://naif.jpl.nasa.gov/naif/toolkit.html).
* Since I was wroking with MinGW in Eclipse it was imposible to compile the project. 
* Finally I installed Cygwin (long procedure choosing packages) and create
a Cygwin Eclipse project from zero.
* Previous, after isntalling Cygwin, I compiled the all library using
the makeall.csh file. 
* Into Eclipse IDE:
	1) Project (right click) -> Properties -> C/C++ Build -> Settings:
		a) -> Cygwin C++ Compiler -> Incudes -> Include paths -> Add -> yourpath/cspice/include
		b) -> Cygwin C++ Linker -> Libraries -> Add -> "cspice" (no lib, no .a)
								-> Library search path -> Add -> yourpath/cspice/lib