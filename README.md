This is a fork of [pschultz/kiosk-browser](https://github.com/pschultz/kiosk-browser) with a modified fullscreen method (that works reliable without a window manager).

This version also uses GTK 3.0 by default and has no method to exit fullscreen.

# COMPILING
    apt install libwebkitgtk-3.0-dev
    make

# USAGE
    browser <URL>

This will launch the browser in fullscreen mode and load the resource at `URL`.
`URL` can be anything that WebKit supports, including `file://`-URLs for local webpages and documents.
Omitting `URL` shows the default page, this README.

These actions are also implemented as signal handlers:
  - `HUP` for reload