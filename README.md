# Image Processing

Image manipulation project using c language. <br>
Its main purpose is to manipulate images in the pnm format.

# Authors
Daniel Pinto, 89341 <br>
Rodrigo Oliveira 90514

# Usage

The program tests two images: lena.ppm and baboon.ppm

```bash
$ cd src
$ make
$ ./ppmtesting
```
At the end of the program execution, the files with changes can be found in the corresponding format folders in /res

# Problems

Due to some problems while developing the project, we were not able to make a correct conversion from grayscale to binary. Instead we compared the grayscale pixel to a threshold and set the new image pixel as 255 or 0. Finally the file was saved in pgm format emulating what the image would look like if it was in pbm format. <br>
This images can be found in /res/pbm

# Reference links for the image formats:

http://netpbm.sourceforge.net/doc/pnm.html

http://netpbm.sourceforge.net/doc/pgm.html

http://netpbm.sourceforge.net/doc/pbm.html

http://netpbm.sourceforge.net/doc/ppm.html
