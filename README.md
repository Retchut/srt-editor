# srt-editor


Simple srt file editing tool created to aid in my manual modification (and occasional creation) of subtitle files.


### Usage
In order to use this application, create a folder called "srt-files" on the root directory of the repo. This will be where you drop the srt files you can later edit using the program.

#### Building
Navigate to the src folder and make:

***make*** (if on an unix-based system)

***mingw32-make.exe*** (if on windows, using gnu make)

#### Running
To run the program, simply run the following command from a terminal, while inside the src folder:

Unix-based: ***./srt-editor hourOffset minOffset secOffset msecOffset srtFile***

Windows:    ***srt-editor.exe hourOffset minOffset secOffset msecOffset srtFile***


Where:

    -xOffset is the offset to add to x

    -srtFile is the name of the subtitle file you want to edit, inside the srt-files folder. It is not the relative path to the folder, nor an absolute path.


#### Notes
Line endings will be preserved, save for the line with the timestamps. The line ending in each timestamp will follow the conventions for the OS this program is run in.
Eventually, I'll take the time to fix this, but it shouldn't cause any issues whatsoever.