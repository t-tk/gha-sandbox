

gha_sb: gha_sb.c
	gcc -c -o gha_sb.o gha_sb.c
	gcc -o gha_sb  gha_sb.o /usr/lib/x86_64-linux-gnu/libicuuc.so

gha_sb2: gha_sb.c
	gcc -o gha_sb2 gha_sb.c `pkg-config --libs --cflags icu-uc icu-io`
