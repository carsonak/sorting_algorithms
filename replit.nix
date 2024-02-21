{ pkgs }: {
	deps = [
		pkgs.coreutils-full
   pkgs.valgrind
		pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}