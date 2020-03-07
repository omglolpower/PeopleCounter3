# PeopleCounter3  
The program is organized the following way:  
  
1) Every frame of the input video is converted to substraction frame:  
if current frame pixel minus previous frame pixel is more than 20 than resulting substraction pixel is 255 and 0 otherwise. It has to be nore than 20 to reduce noise effect;  
2) The program counts the amount of substraction pixels to the left (pixelsL) from the entrance and to the right (pixelsR).  
3) If the pixelsL is more than 750 boolean isL becomes true and false otherwise, the same goes for pixelsR and isR, respectively.
4) If at previous frame (previous iteration of while cycle) isL was true boolean wasL is st to true and false, otherwise. The same goes for isR and wasR.  
5) if isR is true and wasL is true and isL is false we count that one person goes out, and vise a versa for isL, wasL, isR and person going in.  
6) the program is only calibrated to work with the video1.mp4 from res/videos foder.  

Settings for Visual Studio:  
x64 Debug  
VC++ Dir-s:  
1) Include Dir-s: "opencv folder"\build\include;$(IncludePath)  
2) Library dir-s: "opencv folder"\build\x64\vc15\lib;$(LibraryPath)  
  
  Linker:  
  Input: additional Dependencies: opencv_world420d.lib  
    
Debugging: Environment:"opencv folder"\build\x64\vc15\bin

