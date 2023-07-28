#!/bin/sh -vx

bindir=${bindir:-.}
exeext=${exeext:-}
srcdir=${srcdir:-.}
_gha_sb=$bindir/gha_sb$exeext

rm -f ofile.txt out.txt

$_gha_sb --version
$_gha_sb --printenv
$_gha_sb --icuversion
$_gha_sb ofile.txt
$_gha_sb > out.txt
md5sum $srcdir/testdata/gha_sb.txt ofile.txt out.txt
diff $srcdir/testdata/gha_sb.txt out.txt || exit 1

exit 0
