# GaubArcade v2.0

**Lightweight multi-arcade frontend for DietPi / Linux**  
(c) Coyote Prod 2026 — Loldil / PaGauba Special Edition

Frontend SDL2 minimaliste pour lancer des émulateurs standalone (FBNeo, Flycast, Mupen64Plus, Dolphin, SNES9x, Mednafen/PS1, etc.).

## Fonctionnalités

- Navigation **manette + clavier**
- Mapping orienté **jeux de voiture** (stick = direction, A = action, gâchettes = accel/frein une fois dans le jeu)
- Deadzone + anti-répétition du stick
- Fermeture propre des manettes avant lancement émulateur (focus X11)
- Hotplug manettes
- FBNeo isolé (mode `name` / basename)
- Support multi-consoles via `consoles.cfg`
- Mapping d’images persistant (`mapping.tsv`)
- Panneau paramètres (scraping + liste manettes)

## Dépendances (Debian / DietPi)

```bash
sudo apt update
sudo apt install -y build-essential pkg-config \
    libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev \
    fonts-dejavu-core
```

## Compilation

```bash
gcc -O2 -Wall -Wno-format-truncation -o gaubarcade gaubarcade.c \
    -I/usr/include/SDL2 \
    -lSDL2 -lSDL2_image -lSDL2_ttf -lm
```

Ou avec `pkg-config` :

```bash
gcc -O2 -Wall -Wno-format-truncation -o gaubarcade gaubarcade.c \
    $(pkg-config --cflags --libs sdl2 SDL2_image SDL2_ttf) -lm
```

Ou via le Makefile :

```bash
make
```

## Configuration

Copie `consoles.cfg.example` vers ton chemin de config (défaut : `/home/dietpi/work/frontend/consoles.cfg`) et adapte les chemins.

Exemple minimal :

```ini
[Arcade]
roms_dir=/home/dietpi/roms/fbneo
images_dir=/home/dietpi/images/fbneo
emu_bin=/usr/local/bin/fbneo
rom_arg_mode=name
extensions=.zip,.7z

[N64]
roms_dir=/home/dietpi/roms/n64
images_dir=/home/dietpi/images/n64
emu_bin=/usr/games/mupen64plus
extra_args=--nogui
extensions=.n64,.z64,.v64
```

- `rom_arg_mode=name` → FBNeo (passe le nom sans extension)
- `rom_arg_mode=path` (défaut) → chemin complet de la ROM

## Contrôles

| Action              | Manette              | Clavier     |
|---------------------|----------------------|-------------|
| Naviguer            | Stick / D-pad        | Flèches     |
| Changer de console  | Stick X / D-pad L/R  | ← →         |
| Lancer              | A / Start            | Entrée      |
| Quitter / Annuler   | B                    | Échap       |
| Paramètres          | Select               | P           |
| Choisir image       | -                    | I           |

## Licence

Code fourni tel quel pour usage personnel. (c) Coyote Prod 2026.
