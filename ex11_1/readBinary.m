function A = readBinary( filename )
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% readBinary.m
%% (c) JMB 2009 - Jan Martin Brockmann brockmann@geod.uni-bonn.de
%% 
%% last modified on October 27, 2009 by JMB
%%
%% This function reads a binary matrix given in the GDK format
%%
%% readBinary( '/path/to/matrix/A.dat' )
%% readBinary( 'relpath/to/matrix/A.dat' )
%%
%% You can set the following parameters
%%   *  filename: absolute or relative path to the gdk matrix file
%%   
%% returns
%%   *  A: the matrix as MATLAB matrix
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


% open the file to read

fid = fopen( filename, 'r' );
r = fread(fid, 1, 'int');
c = fread(fid, 1, 'int');

% allocate matrix memory
A = fread(fid, r*c, 'double');
A = reshape( A, r, c );
fclose(fid);

return
