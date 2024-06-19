#include "OutputService.h"

void OutputService::printHelp()
{
    std::cout << "Raster graphics program guide:\n\n";

    std::cout << "grayscale -> makes the image grayscale\n";
    std::cout << "Applies grayscale transformation to all color images in the current session. If an image is already grayscale, it will not be modified.\n\n";

    std::cout << "monochrome -> makes the image monochrome (black and white)\n";
    std::cout << "Converts images to monochrome. If an image is already monochrome, it remains unchanged.\n\n";

    std::cout << "negative -> makes the image negative\n";
    std::cout << "Applies negative (color inversion) transformation to all images in the current session.\n\n";

    std::cout << "rotate <direction> -> rotates the image 90 degrees\n";
    std::cout << "<direction> can be either 'left' or 'right'. Rotates all images 90 degrees in the specified direction.\n\n";

    std::cout << "undo -> undoes the last transformation\n";
    std::cout << "Removes the last transformation applied in the current session. If no transformation has been applied, this command has no effect.\n\n";

    std::cout << "add <image> -> adds an image to the current session\n";
    std::cout << "Adds the image <image> to the current session. Any transformations applied so far will not affect this new image.\n\n";

    std::cout << "session info -> displays information about the current session\n";
    std::cout << "Provides detailed information about the current session including its ID, participating images, and the set of transformations to be applied to each image.\n\n";

    std::cout << "switch <session> -> switches to a different session\n";
    std::cout << "Switches to the session with the given ID <session>. If no such session exists, an appropriate error message is displayed.\n\n";

    std::cout << "collage <direction> <image1> <image2> <outimage> -> creates a collage from two images\n";
    std::cout << "<direction> can be either 'horizontal' or 'vertical'. Creates a collage from <image1> and <image2> (which must be in the same format and size) in the specified direction. The result is saved as <outimage> and added to the current session.\n";
}
