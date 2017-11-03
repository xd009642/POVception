import os
import glob

contents = "#ifndef BACKGROUND_H\n#define BACKGROUND_H\n\n\n"
for image in glob.iglob('resources/*.bmp'):
    contents += os.popen("xxd -i "+image).read()
    contents+="\n"
contents +="\n\n#endif"
file = open("src/background.h", "w")
file.write(contents) 


