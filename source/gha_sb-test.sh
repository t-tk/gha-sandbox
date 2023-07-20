#!/bin/sh -vx

bin=${bin:-.}
exe=${exe:-}
_gha_sb=$bin/gha_sb$exe


$_gha_sb > out.txt
diff gha_sb.txt out.txt || exit 1

exit 0
