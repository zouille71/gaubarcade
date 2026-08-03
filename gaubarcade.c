/*
 * gaubarcade.c - GaubArcade v2.0
 * (c) Coyote Prod 2026
 *
 * The full source lives on the DietPi machine where you compiled it:
 *   ~/work/gaubarcade-v2/gaubarcade.c
 *
 * To publish it to this repo (from DietPi):
 *
 *   cd ~/work/gaubarcade-v2
 *   git clone https://github.com/zouille71/gaubarcade.git tmp-repo
 *   cp gaubarcade.c tmp-repo/
 *   cd tmp-repo
 *   git add gaubarcade.c
 *   git commit -m "Add full GaubArcade v2.0 source"
 *   git push
 *
 * Or with the GitHub CLI (if installed):
 *   gh repo clone zouille71/gaubarcade
 *   cp ~/work/gaubarcade-v2/gaubarcade.c gaubarcade/
 *   cd gaubarcade && git add . && git commit -m "Full source" && git push
 *
 * Build (once the full file is here):
 *   make
 *   # or:
 *   gcc -O2 -Wall -Wno-format-truncation -o gaubarcade gaubarcade.c \
 *       -I/usr/include/SDL2 -lSDL2 -lSDL2_image -lSDL2_ttf -lm
 */

#error "Upload the full gaubarcade.c from ~/work/gaubarcade-v2/ on your DietPi (see comment above)"
