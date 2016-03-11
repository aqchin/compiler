#! /bin/sh

[ -x glc ] || { echo "Error: glc not executable"; exit 1; }

LIST=
if [ "$#" = "0" ]; then
	LIST=`ls samples/*.out`
else
	for test in "$@"; do
		LIST="$LIST samples/$test.out"
	done
fi

for file in $LIST; do
	base=`echo $file | sed 's/\(.*\)\.out/\1/'`

	ext=''
	if [ -r $base.frag ]; then
		ext='frag'
	elif [ -r $base.glsl ]; then
		ext='glsl'
	else
		echo "Error: Input file for base: $base not found"
		exit 1
	fi

	tmp=foo.bc
	dat=foo.dat
	out=foo.out
	cp -f $base.dat $dat
	printf "Checking %-27s: " $file
	./glc < $base.$ext > $tmp 2>&1
	./gli $tmp > $out

	if ! cmp -s $out $file; then
		echo "FAIL <--"
		diff $out $file
	else
		echo "PASS"
	fi
done
