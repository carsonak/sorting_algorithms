{ pkgs }: {
	deps = [
		pkgs.coreutils-full
		pkgs.man-db
		pkgs.valgrind
		pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}