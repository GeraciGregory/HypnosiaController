( Made using CamBam - http://www.cambam.co.uk )
( front_Box 7/14/2020 5:44:34 PM )
( Post processor: Default )
( T2 : 2.0 )
G21 G90 G64 G40
G0 Z10.0
( T2 : 2.0 )
T2 M6
( Contour2 )
G17
M3 S3000
G0 X264.0 Y673.0
G0 Z1.0
G1 F300.0 Z-3.5
G1 F800.0 X24.0
G3 X-1.0 Y648.0 I0.0 J-25.0
G1 Y24.0
G3 X24.0 Y-1.0 I25.0 J0.0
G1 X264.0
G3 X289.0 Y24.0 I0.0 J25.0
G1 Y648.0
G3 X264.0 Y673.0 I-25.0 J0.0
G0 Z10.0
M5
M30
