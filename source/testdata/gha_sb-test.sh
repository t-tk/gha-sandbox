#!/bin/sh -vx

bindir=${bindir:-.}
exeext=${exeext:-}
srcdir=${srcdir:-.}
_gha_sb=$bindir/gha_sb$exeext

DIFF=diff
if [ $exeext = ".exe" ]; then
$DIFF --strip-trailing-cr $0 $0 \
  && DIFF="diff --strip-trailing-cr" || echo "failed to set --strip-trailing-cr for diff"
fi

rm -f out.txt

$_gha_sb --version
$_gha_sb > out.txt
md5sum $srcdir/testdata/gha_sb.txt out.txt
$DIFF $srcdir/testdata/gha_sb.txt out.txt || exit 1

exit 0
