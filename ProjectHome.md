SCMLpp is a C++ API for loading and using the [Spriter](http://www.brashmonkey.com/spriter.htm) SCML animation data format.

See [GETTING\_STARTED.txt](http://code.google.com/p/scml-pp/source/browse/trunk/GETTING_STARTED.txt) for usage info.

The project goal is to keep SCMLpp up-to-date with the latest Spriter capabilities (currently Spriter A4.1).

Current state:
  * Loads the full SCML structure into C++ objects.
  * Draws keyframed entities
  * Tweening support
  * Bone animation
  * Scaling and rotation of whole entity
  * Multiple renderers
    * [SDL\_gpu](http://code.google.com/p/sdl-gpu/) (a reference implementation)
    * [SPriG](http://code.google.com/p/sprig/) (no GPU)
    * [SFML 2.0](http://www.sfml-dev.org)

Not yet implemented:
  * Metadata variable tweening
  * Non-linear tweening
  * Blend modes
  * Sound effects, collision boxes, etc.
  * Atlases
  * Character maps
  * Pixel art mode

Note: Renderer headers and library files are included for convenience when compiling and linking the test program, but are subject to their respective licenses and may be incomplete.