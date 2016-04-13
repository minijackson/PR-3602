#! /bin/bash
DIRECTORY_TO_OBSERVE="graphs"
function block_for_change {
  inotifywait -r \
    -e modify,move,create,delete \
    $DIRECTORY_TO_OBSERVE
}

while block_for_change; do
    for f in graphs/*.dot
    do
        dot -Tsvg $f > $f.svg
    done
done
