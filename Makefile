all: SLL DLL CLL MDLL ULL

%: %.cc
	g++ -std=c++11 $< -o $@

%: %.c
	gcc $< -o $@

