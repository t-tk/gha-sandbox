#!/bin/sh -vx

bindir=${bindir:-.}
exeext=${exeext:-}
srcdir=${srcdir:-.}
_gha_sb=$bindir/gha_sb$exeext

rm -f out.txt

$_gha_sb > out.txt
diff $srcdir/testdata/gha_sb.txt out.txt || exit 1

exit 0
