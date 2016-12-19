all: SLL DLL hello-c-world

%: %.cc
	g++ -std=c++11 $< -o $@

%: %.c
	gcc $< -o $@

