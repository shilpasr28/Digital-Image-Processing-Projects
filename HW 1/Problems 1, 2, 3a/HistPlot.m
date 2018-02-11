clear;
format longG;
InHistR = importdata('Indata_histR.dat');
InHistG = importdata('Indata_histG.dat');
InHistB = importdata('Indata_histB.dat');

OutAHistR = importdata('OutAdata_histR.dat');
OutAHistG = importdata('OutAdata_histG.dat');
OutAHistB = importdata('OutAdata_histB.dat');

OutBHistR = importdata('OutBdata_histR.dat');
OutBHistG = importdata('OutBdata_histG.dat');
OutBHistB = importdata('OutBdata_histB.dat');

RDataLena = importdata('RHist.dat');
GDataLena = importdata('GHist.dat');
BDataLena = importdata('BHist.dat');

Intensity = importdata('IntensityVal.dat');
yInR = InHistR(:,1);
yInG = InHistG(:,1);
yInB = InHistB(:,1);

yOutAR = OutAHistR(:,1);
yOutAG = OutAHistG(:,1);
yOutAB = OutAHistB(:,1);

yOutBR = OutBHistR(:,1);
yOutBG = OutBHistG(:,1);
yOutBB = OutBHistB(:,1);

yRLena = RDataLena(:,1);
yGLena = GDataLena(:,1);
yBLena = BDataLena(:,1);

x = Intensity(:,1);
figure(1)
stem(x,yInR)
title('R Channel - Input Image');
xlabel('Intensity values');
ylabel('Number of pixels');
figure(2)
stem(x,yInG)
title('G Channel - Input Image');
xlabel('Intensity values');
ylabel('Number of pixels');
figure(3)
stem(x,yInB)
title('B Channel - Input Image');
xlabel('Intensity values');
ylabel('Number of pixels');

figure(4)
stem(x, yOutAR)
title('R Channel Transfer function - Output Image (Method A)');
xlabel('Intensity values');
ylabel('Number of pixels');

figure(5)
stem(x, yOutAG)
title('G Channel Transfer function - Output Image (Method A)');
xlabel('Intensity values');
ylabel('Number of pixels');

figure(6)
stem(x, yOutAB)
title('B Channel Transfer function - Output Image (Method A)');
xlabel('Intensity values');
ylabel('Number of pixels');

figure(7)
stem(x, yOutBR)
title('R Channel Cumulative Histogram - Output Image (Method B)');
xlabel('Intensity values');
ylabel('Number of pixels');

figure(8)
stem(x, yOutBG)
title('G Channel Cumulative Histogram - Output Image (Method B)');
xlabel('Intensity values');
ylabel('Number of pixels');

figure(9)
stem(x, yOutBB)
title('B Channel Cumulative Histogram - Output Image (Method B)');
xlabel('Intensity values');
ylabel('Number of pixels');

figure(10)
stem(x, yRLena)
title('R Channel Lena Histogram');
xlabel('Intensity values');
ylabel('Number of pixels');

figure(11)
stem(x, yGLena)
title('G Channel Lena Histogram');
xlabel('Intensity values');
ylabel('Number of pixels');

figure(12)
stem(x, yBLena)
title('B Channel Lena Histogram');
xlabel('Intensity values');
ylabel('Number of pixels');

