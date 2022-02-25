# uEye SDK CMake
`FinduEye-SDK.cmake` will find an installation of the *IDS Imaging Development Systems GmbH [uEye-SDK](https://de.ids-imaging.com/ids-software-suite.html)* on your machine and create a CMake library-target to link against in your project.

```cmake
# allow CMake to find our find-script
set (CMAKE_MODULE_PATH <path-to-FinduEye-SDK.cmake-directory> ${CMAKE_MODULE_PATH})

# package and variable names are case-sensitive!
# supports version requirements
find_package( uEye-SDK 4.95)
...

target_link_libraries( <your-target> uEye-SDK )
```
32 and 64-bit versions are auto detected per your platform. The SDK is searched for in the default installation paths on Windows and Linux. If the location of the SDK cannot be determined, you have to point the find script in the right direction by using the variables listed below. When using a graphical interface for CMake, only missing variables will be show in non-advanced mode. With a default installation, or when adhering to **NIX* standard locations, only `uEye-SDK` should be needed, to define a common root for headers an libraries.

Requesting version requirements is supported. Currently no support for handling multiple installed versions!

> 📌 Old and new **NIX* install-locations are supported

## exported library targets
* `uEye-SDK`
> 📌 Library target includes link directories

## exported variables
* `uEye-SDK_INCLUDE_DIRS`
* `uEye-SDK_LIBRARIES`
* `uEye-SDK_FOUND`
* `uEye-SDK_VERSION`

## manual location setup
If the SDK could not be found, you may help with providing following variables:
* `uEye-SDK`: defines a common root directory for library and headers. *Headers* may be in subdirectories `/.;/include;/usr/include;/usr/local/include` and *libraries* in `/.;/Lib;/lib;/lib64;/i386-linux-gnu;/x86_64-linux-gnu` (*depending on platform*)
* `uEye-SDK_INCLUDE_DIRS`: sets the include directories directly
* `uEye-SDK_LIBRARIES`: sets the libraries directly
