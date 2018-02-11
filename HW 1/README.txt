OS Version: Windows 10 
Compiler: g++
Codes were run on Bash Ubuntu (g++ compiler)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Problem 1a1: Color to Grayscale Conversion

Cpp File Name: Problem1a1.cpp

Command on terminal: 
g++ Problem1a1.cpp
 ./a.out images_v2/images/p1/Tiffany.raw 3 512

Output file names: lightness_output.raw, average_output.raw, luminosity_output.raw
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Problem 1a2: CMYK color space

Cpp File Name: Problem1a2.cpp

Command on terminal: 
g++ Problem1a2.cpp
 ./a.out images_v2/images/p1/Bear.raw 3 854 480

Output file names: C_output, M_output, Y_output

Command on terminal: 
g++ Problem1a2.cpp
 ./a.out images_v2/images/p1/Dance.raw 3 854 480

Output file names: C_output.raw, M_output.raw, Y_output.raw
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Problem 1b: Bilinear Interpolation

Cpp File Name: Problem1b.cpp

Command on terminal: 
g++ Problem1b.cpp
 ./a.out images_v2/images/p1/Airplane.raw 3 512

Output file names: bilinear_output.raw
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Problem 2a: Histogram Equalisation

Cpp File Name: Problem2a.cpp

Command on terminal: 
g++ Problem2a.cpp
 ./a.out images_v2/images/p2/Desk.raw 3 400 300

Output file names: methodA_output.raw, methodB_output.raw, OutAdata_histR.dat, OutAdata_histG.dat, OutAdata_histB.dat,
OutBdata_histR.dat, OutBdata_histG.dat, OutBdata_histB.dat, IntensityVal.dat

To view Histograms: Run the HistPlot.m
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Problem 2b: Oil Painting

Cpp File Name: Problem2b.cpp

Command on terminal: 
g++ Problem2b.cpp
 ./a.out images_v2/images/p2/Star_Wars.raw 3 600 338 5

Output file names: Quantized_output.raw, OilPainted_output.raw

Command on terminal: 
g++ Problem2b.cpp
 ./a.out images_v2/images/p2/Trojans.raw 3 720 480 5

Output file names: Quantized_output.raw, OilPainted_output.raw

Cpp File Name: Problem2b3.cpp (for 512 colors)

Command on terminal: 
g++ Problem2b3.cpp
 ./a.out images_v2/images/p2/Star_Wars.raw 3 600 338 5
 ./a.out images_v2/images/p2/Trojans.raw 3 720 480 5

Output file names: Quantized_output_512.raw, OilPainted_output_512.raw
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Problem 2c: Film effect

Cpp File Name: Problem2c.cpp

Command on terminal: 
g++ Problem2c.cpp
 ./a.out images_v2/images/p2/Girl.raw 3 256 256

Output file names: Film_image.raw
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Problem 3a: Noise Removal (The mean filter window size is hardcoded to 5)

Cpp File Name: Problem3a.cpp

Command on terminal: 
g++ Problem3a.cpp
./a.out images_v2/images/p3/Lena.raw images_v2/images/p3/Lena_mixed.raw 3 512 5

Output file names: Rchannel_output.raw, Gchannel_output.raw, Bchannel_output.raw, Median+Mean_output.raw, 
RHist.dat, GHist.dat, BHist.dat, IntensityVal.dat

To plot the histograms: Run HistPlot.m
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%




