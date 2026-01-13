# Retro Math Effects (SDL2)

A collection of classic retro visual effects implemented in pure C using SDL2.  
All effects are generated with simple mathematics — no shaders, no textures, just code.

Inspired by old-school games and demoscene visuals from the DOS / Amiga era.

Included effects:

- Fire
- Tunnel
- Starfield
- Plasma
- Metaballs
- Water ripple
- Rain
- Orbit
- Bounce
- Mode 7
- RotoZoom
- Value / Perlin-like Noise  
- And more…

Each effect lives in its own folder and builds into a standalone executable.

## Requirements

- SDL2 development libraries  
- A C compiler (clang or gcc)

On macOS:

```bash
brew install sdl2
````

On Linux (Debian/Ubuntu):

```bash
sudo apt install libsdl2-dev
```

## Build

Compile all effects at once:

```bash
make
```

This will enter each subfolder and build the corresponding demo.

## Run

Each effect produces a `main` binary inside its folder:

```bash
./fire_math/main
./tunnel_effect/main
./starfield/main
./plasma/main
# etc...
```

Press **ESC** to exit any demo.
