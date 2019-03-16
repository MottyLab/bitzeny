#!/bin/bash

TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
SRCDIR=${SRCDIR:-$TOPDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

BITZENYD=${BITZENYD:-$SRCDIR/bitzenyd}
BITZENYCLI=${BITZENYCLI:-$SRCDIR/bitzeny-cli}
BITZENYTX=${BITZENYTX:-$SRCDIR/bitzeny-tx}
BITZENYQT=${BITZENYQT:-$SRCDIR/qt/bitzeny-qt}

[ ! -x $BITZENYD ] && echo "$BITZENYD not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
BTCVER=($($BITZENYCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
# This gets autodetected fine for bitzenyd if --version-string is not set,
# but has different outcomes for bitzeny-qt and bitzeny-cli.
echo "[COPYRIGHT]" > footer.h2m
$BITZENYD --version | sed -n '1!p' >> footer.h2m

for cmd in $BITZENYD $BITZENYCLI $BITZENYTX $BITZENYQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${BTCVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${BTCVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
