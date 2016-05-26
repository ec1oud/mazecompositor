Qt 5 / qtwayland based toy 3D compositor modified for Oculus Rift

Showcases the use of qtwayland's compositor API for creating a 3D wayland compositor.
Head tracking is used to rotate your view; otherwise you can use the keyboard the same way
as in the original version.  Start it like this:
```
mazecompositor -s -f
```
where -s means "stereo" and -f means "fullscreen".

Depends on OSVR, and the OSVR Oculus Rift plugin, which in turn depends on the Rift SDK.
Requires Qt 5.7 or later (that's not released yet, you'll need to use a prerelease, or build it from git).

On Arch Linux, install the following packages:
- aur/oculus-udev
- aur/oculus-rift-sdk
- aur/osvr-core-git
- aur/osvr-libfunctionality-git
- aur/osvr-oculus-rift-git
- aur/osvr-tracker-viewer-git (optional, to verify head tracking)

Follow https://wiki.archlinux.org/index.php/Oculus_Rift to set up the Rift as primary and rotated.

![Screenshot of mazecompositor](https://github.com/ec1oud/mazecompositor/blob/master/screenshot.png)

As you can see, in this version there is not yet any lens distortion correction.

Attributions:

boiler_plate.jpg and boiler_plate_rust.jpg are from http://www.grsites.com/

The soldier images are from the Wolfenstein 3D Texture Library, http://www.areyep.com/RIPandMCS-TextureLibrary.html
