# Console Raster Image Editor
Welcome to the Console Raster Image Editor! This application allows you to edit raster images using a variety of transformations through a command-line interface. The editor supports multiple sessions and can handle various image formats including PPM, PGM, and PBM.

## Features
- Load and manage multiple image files within sessions
- Apply transformations such as grayscale, monochrome, negative, and rotate
- Save edited images with or without new names
- Undo transformations within the current session
- Create collages from existing images
- Get detailed session information
- Switch between different sessions

## Supported File Formats
The editor supports the following file formats:

- PPM (Portable Pixmap)
- PGM (Portable Graymap)
- PBM (Portable Bitmap)
  
For more information about these formats, please visit the Netpbm format [Wikipedia page](http://en.wikipedia.org/wiki/Netpbm_format).

## Commands
### Session Management
- Load an Image: `load <filename1> <filename2> ...`
  - Starts a new session with the given image files.
  
- Save Images: `save`
  - Saves all images in the current session after applying transformations.
    
- Save As: `saveas <new_filename>`
  - Saves the first loaded image in the current session under a new name.

- Add Image: `add <filename>`
  - Adds a new image to the current session without applying previous transformations.

- Close Session: `close`
  - Closes the current session.
  
- Session Information: `session info`
  - Displays detailed information about the current session, including session ID, loaded images, and pending transformations.
    
- Switch Session: `switch <session_id>`
  - Switches to a different session by its ID.
  
### Image Transformations
- Grayscale: `grayscale`
  - Applies grayscale transformation to all color images in the current session.
  
- Monochrome: `monochrome`
  - Converts all images in the current session to monochrome (black and white).
    
- Negative: `negative`
  - Applies a negative effect to all images in the current session.
  
- Rotate: `rotate <direction>`
  - Rotates all images in the current session by 90 degrees in the specified direction (left or right).
  
- Undo: `undo`
  - Undoes the last transformation applied in the current session.
  
- Create Collage: `collage <direction> <image1> <image2> <outimage>`
  - Creates a collage from two images in the current session and saves it as a new image.
      - `<direction>` can be either horizontal or vertical.
### General
- Help: help
  - Displays a list of available commands and their descriptions.
- Exit: exit
  - Exits the application.

## License
This project is licensed under the MIT License.
